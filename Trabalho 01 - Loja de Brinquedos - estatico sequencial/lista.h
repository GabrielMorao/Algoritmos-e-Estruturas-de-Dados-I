#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#define MAX 1000


typedef struct{
    int num_serial;
    char nome[50];
}brinquedo;

typedef struct{
    int pos;
    brinquedo vet[MAX];
    int tam_lista;
}lista;

void cria_lista(lista *l);
int insere_na_lista(lista *l,brinquedo toy);
int vazia_lista(lista *l);
int cheia_lista(lista *l);
int remove_da_lista(lista *l, int *pos, brinquedo *toy);

#endif // LISTA_H_INCLUDED
