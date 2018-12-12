#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

void cria_abb(ABB *a) {
    a->raiz = NULL;
    return;
}

int buscaSub(No_abb *p, elem x) {
    if (p == NULL)
        return 0; // nao achou
    if (p->info == x)
        return 1; // achou
    return (x < p->info) ? buscaSub(p->esq, x) : buscaSub(p->dir, x); // busca na subarvore apropriada
}

int busca_abb(ABB a, elem x) {
    return buscaSub(a.raiz, x);
}

No_abb *criaNo_abb(elem info, No_abb *esq, No_abb *dir) {
    No_abb *nova = malloc(sizeof(No_abb));
    if (nova != NULL) {
        nova->info = info;
        nova->esq = esq;
        nova->dir = dir;
    }
    return nova;
}

int insereSub_abb(No_abb **p, elem x) {
    // p => No**; *p => No*; **p => No
    if (*p == NULL) { // nao achou, entao insere
        *p = criaNo_abb(x, NULL, NULL);
        return *p == NULL; // erro de memoria ou sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, elemento ja cadastrado
    return (x < (*p)->info) ? insereSub_abb(&((*p)->esq), x) : insereSub_abb(&((*p)->dir), x); // insere na subarvore apropriada
}

int insere_abb(ABB *a, elem x) {
    return insereSub_abb(&(a->raiz), x);
}

int removerSub_abb(No_abb **p, elem x) {
    // p => No**; *p => No*; **p => No
    int numFilhos = 0;
    No_abb *aux, *paiAux;
    if (*p == NULL)
        return 1; // erro, elemento nao existe
    if ((*p)->info == x) { // achou, entao remove
        if ((*p)->esq != NULL)
            numFilhos++;
        if ((*p)->dir != NULL)
            numFilhos++;
        switch (numFilhos) {
            case 0: // nenhum filho
                free(*p); // apaga no
                *p = NULL; // atualiza encadeamento
                return 0; // sucesso
            case 1: // um filho
                aux = *p;
                *p = ((*p)->esq != NULL) ? (*p)->esq : (*p)->dir; // atualiza encadeamento
                free(aux); // apaga no
                return 0; // sucesso
            case 2: // dois filhos
                // acha maior na subarvore esquerda
                aux = (*p)->esq;
                paiAux = *p;
                while (aux->dir != NULL) {
                    paiAux = aux;
                    aux = aux->dir;
                }
                (*p)->info = aux->info; // copia informacao
                return (paiAux->esq == aux) ? removerSub_abb(&(paiAux->esq), aux->info) : removerSub_abb(&(paiAux->dir), aux->info); // apaga e atualiza encadeamento
        }
    }
    return (x < (*p)->info) ? removerSub_abb(&((*p)->esq), x) : removerSub_abb(&((*p)->dir), x); // insere na subarvore apropriada
}

int remover_abb(ABB *a, elem x) {
    return removerSub_abb(&(a->raiz), x);
}

void destroiSub_abb(No_abb *p) {
    if (p != NULL) {
        destroiSub_abb(p->esq); // destroi subarvore esquerda
        destroiSub_abb(p->dir); // destroi subarvore direita
        free(p); // apaga o no
    }
    return;
}

void destroi_abb(ABB *a) {
    destroiSub_abb(a->raiz); // inicia recursividade
    a->raiz = NULL;
    return;
}
