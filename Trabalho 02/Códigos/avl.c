#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

void cria_avl(AVL *a) {
    a->raiz = NULL;
    return;
}

int vazia_avl(AVL a) {
    return a.raiz == NULL;
}

int buscaSub_avl(No_avl *p, elem x) {
    if (p == NULL)
        return 0; // nao achou
    if (p->info == x)
        return 1; // achou
    return (x < p->info) ? buscaSub_avl(p->esq, x) : buscaSub_avl(p->dir, x); // busca na subarvore apropriada
}

int busca_avl(AVL a, elem x) {
    return buscaSub_avl(a.raiz, x);
}

// rotacao simples a esquerda
void E(No_avl **p) {
    // p => No**; *p => No*; **p => No
    No_avl *novaRaiz, *realoca;
    novaRaiz = (*p)->dir;
    realoca = novaRaiz->esq;
    novaRaiz->esq = *p;
    (*p)->dir = realoca;
    *p = novaRaiz;
    return;
}

// rotacao simples a direita
void D(No_avl **p) {
    // p => No**; *p => No*; **p => No
    No_avl *novaRaiz, *realoca;
    novaRaiz = (*p)->esq;
    realoca = novaRaiz->dir;
    novaRaiz->dir = *p;
    (*p)->esq = realoca;
    *p = novaRaiz;
    return;
}

// rotacao dupla esquerda-direita
void ED(No_avl **p) {
    E(&((*p)->esq)); // roda filho esquerdo para a esquerda
    D(p); // roda raiz para a direita
    return;
}

// rotacao dupla direita-esquerda
void DE(No_avl **p) {
    D(&((*p)->dir)); // roda filho direito para a direita
    E(p); // roda raiz para a esquerda
    return;
}

No_avl *criaNo_avl(elem info, No_avl *esq, No_avl *dir, int fb) {
    No_avl *nova = malloc(sizeof(No_avl));
    if (nova != NULL) {
        nova->info = info;
        nova->esq = esq;
        nova->dir = dir;
        nova->fb = fb;
    }
    return nova;
}

// atualiza fatores de balanceamento apos rotacao dupla
int atualizaFB_avl(No_avl *p) {
    switch (p->fb) {
        case 0:
            p->esq->fb = 0;
            p->dir->fb = 0;
            break;
        case 1:
            p->esq->fb = -1;
            p->dir->fb = 0;
            break;
        case -1:
            p->esq->fb = 0;
            p->dir->fb = 1;
            break;
    }
    p->fb = 0;
    return p->fb;
}

int insereSub_avl(No_avl **p, elem x, int *cresceu) {
    // p => No**; *p => No*; **p => No
    int retorno;
    if (*p == NULL) { // nao achou, entao insere
        *p = criaNo_avl(x, NULL, NULL, 0);
        *cresceu = 1; // subarvore cresceu; era nula e agora tem o raiz
        return *p == NULL; // erro de memoria ou sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, elemento ja cadastrado
    retorno = insereSub_avl((x < (*p)->info) ? &((*p)->esq) : &((*p)->dir), x, cresceu); // insere na subarvore apropriada
    if (!retorno && *cresceu) { // so faz algo se inseriu com sucesso e a subarvore apropriada cresceu
        (*p)->fb += (x < (*p)->info) ? -1 : 1; // atualiza fator de balanceamento
        if ((*p)->fb == 0 || (*p)->fb == 2 || (*p)->fb == -2) {
            *cresceu = 0; // arvore parou de crescer: 0 => melhorou o balanceamento; 2 ou -2 => desbalanceamento sera corrigido na sequencia
            switch ((*p)->fb) {
                case 2: // arvore desbalanceada a direita
                    if ((*p)->dir->fb == 1) { // sinais iguais
                        E(p); // rotacao simples a esquerda
                        // atualiza fatores de balanceamento
                        (*p)->fb = 0;
                        (*p)->esq->fb = 0;
                    } else { // sinais opostos
                        DE(p); // rotacao dupla direita-esquerda
                        atualizaFB_avl(*p); // atualiza fatores de balanceamento
                    }
                    break;
                case -2: // arvore desbalanceada a esquerda
                    if ((*p)->esq->fb == -1) { // sinais iguais
                        D(p); // rotacao simples a direita
                        // atualiza fatores de balanceamento
                        (*p)->fb = 0;
                        (*p)->dir->fb = 0;
                    } else { // sinais opostos
                        ED(p); // rotacao dupla esquerda-direita
                        atualizaFB_avl(*p); // atualiza fatores de balanceamento
                    }
                    break;
            }
        }
    }
    (*p)->alt = maior(alt_No((*p)->esq), alt_No((*p)->dir)) + 1;
    return retorno;
}

int insere_avl(AVL *a, elem x) {
    int cresceu;
    return insereSub_avl(&(a->raiz), x, &cresceu);
}

int alt_No(No_avl*no){
    if(no==NULL){
        return 1;
    }
    else{
        return no->alt;
    }
}

int FB(No_avl*no){
    return labs(alt_No(no->esq) - alt_No(no->dir)); //retorna valor absoluto da diferença entre direita e esquerda
}

int maior(int x, int y){ //Verifica qual lado é maior
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

No_avl* procuraMenor(No_avl*atual){ //função que procura o menor valor 
    No_avl *no1 = atual;
    No_avl *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_avl(No_avl **raiz, elem x){
    if(*raiz == NULL){ // arvore vazia ou não achou o valor x
        return 0; //Erro
    }
    int flag;
    if((*raiz)->info > x){
        if((flag=remove_avl(&(*raiz)->esq, x))==1){
            if(FB(*raiz) >= 2){ // Comparação com maior apenas pois utilizou função labs
                if(alt_No((*raiz)->dir->esq) <= alt_No((*raiz)->dir->dir)){
                    D(raiz);
                }
                else{
                    DE(raiz);
                }
            }
        }
    }
    if((*raiz)->info < x){
        if(flag=remove_avl(&(*raiz)->dir, x) == 1){
            if(FB(*raiz) >=2){ // Comparação com maior apenas pois utilizou função labs
                if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq)){
                    E(raiz);
                }
                else{
                    ED(raiz);
                }
            }
        }
    }
    if((*raiz)->info == x){ //achou a pos
        if(((*raiz)->esq==NULL || (*raiz)->dir==NULL)){ //Verifica se um dos filhos é nulo
            No_avl *antNo = (*raiz);
            if((*raiz)->esq !=NULL){ 
                *raiz = (*raiz)->esq;
            }
            else{
                *raiz = (*raiz)->dir;
            }
            free(antNo);
    }
    else{ //2 filhos
        No_avl *temp = procuraMenor((*raiz)->dir); //procura o menor da direita
        (*raiz)->info = temp->info; //atualiza "raíz"
        remove_avl(&(*raiz)->dir, (*raiz)->info);
        if(FB(*raiz) >=2){ // Comparação com maior apenas pois utilizou função labs
            if(alt_No((*raiz)->esq->dir) <= alt_No((*raiz)->esq->esq)){
                E(raiz);
            }
            else{
                ED(raiz);
            }
        }
    }
    return 0;
}
return flag;
}

int remover(AVL *a, int x){
    return remove_avl(&(a->raiz), x);
}
