#include <stdlib.h>
#include <stdio.h>
#include "lfreq.h"

void cria_lista_lfreq(Listad *l) {
    l->ini = NULL;
    l->fim = NULL;
    l->tam_lista = 0;
    return;
}

int insere_lfreq(Listad *l, elem x) {
    No_lfreq *atual, *ant;
    No_lfreq *novac = malloc(sizeof(No_lfreq)); // cria caixa
    if (novac == NULL){
        return 1; // erro
    }
    novac->num_busca = 0;
    novac->info = x; // copia info
    if (l->ini == NULL) { // lista vazia
        novac->prox = NULL;
        novac->ant = NULL;
        l->ini = novac;
        l->fim = novac;
    }
    else { // lista nao vazia
        atual = l->ini;
        while (atual != l->fim) {
            atual = atual->prox;
        }
          if (atual == l->fim) { // insere no final
                novac->ant = l->fim;
                l->fim->prox = novac;
                l->fim = novac;
            }
    }
    /*com isso a lista fica circular*/
    l->fim->prox = l->ini;
    l->tam_lista++;
    return 0; // sucesso
}

int busca_lfreq(Listad *l, elem x){
   No_lfreq *atual = l->ini;
    //int tam = 0;
    while (atual->info != x) {
        atual = atual->prox;
        if(atual == l-> fim && atual->info != x){
            return 1; //Erro, valor não encontrado
        }
    }
                if(atual == l->ini){
                    atual->num_busca++;
                }
                else{
                   //incrementa numero de buscas do no anterior ao procurado
                    atual->num_busca++;
                    //Troca o conteudo do nó atual com o anterior
                    elem aux = atual->ant->info;
                    int aux2 = atual->ant->num_busca;
                    atual->ant->info = atual->info;
                    atual->ant->num_busca = atual->num_busca;
                    atual->info = aux;
                    atual->num_busca = aux2;
                }
    return 0;
}

int remover_lfreq(Listad *l, int x)
{
    No_lfreq *prev=NULL, *p = l->ini;

    if(p==NULL)
    return 1; // Erro, lista vazia

    while(p->info != x){
            if(p->prox == l->ini){
                return 1; //Erro, elemento nao esta na lista
            }
            prev = p;
            p = p->prox;
    }

    if(p->prox == l->ini && prev == l->ini){ //So existe um no
        l->ini = NULL;
        free(p);
        return 0; //Removeu unico no
    }

    p->prox->ant = p->ant;
    p->ant->prox = p->prox;

    if(p == l->ini){
        l->ini = l->ini->prox;
    }
    free(p);

    return 0; // sucesso, achou e removeu
}
