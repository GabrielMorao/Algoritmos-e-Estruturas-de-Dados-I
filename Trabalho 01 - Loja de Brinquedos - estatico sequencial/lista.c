#ifndef LISTA_C_INCLUDED
#define LISTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void cria_lista(lista *l){

    l->pos = -1;
    l->tam_lista = 0;
}

int insere_na_lista(lista *l,brinquedo toy){

   l->pos++;
   l->vet[l->pos] = toy;
   l->tam_lista++;
    return 0;
}

int vazia_lista(lista *l){
    if(l->tam_lista == 0){
        return 1; // lista esta vazia;
    }
    return 0;
}

int cheia_lista(lista *l){
    if(l->pos == MAX-1){
        l->pos = 0;
        return 1; // lista esta cheia
    }
    return 0;
}

int remove_da_lista(lista *l, int *pos, brinquedo *toy){
    while(strcmp(l->vet[*pos].nome,"-2")== 0){
        *pos = *pos + 1;
    }
    *toy = l->vet[*pos];
    strcpy(l->vet[*pos].nome,"-2");
    l->tam_lista--;
    return 0;
}

#endif // LISTA_C_INCLUDED
