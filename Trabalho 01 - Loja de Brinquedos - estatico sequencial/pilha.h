#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "lista.h"

/*aqui foi incluida a lista.h pois nela ja estao contidas
as estruturas de no e brinquedo além da definição de max*/

typedef struct{
    int tam_caixa;
    int topo;
    int num_elementos;
    brinquedo *vet;
}pilha;


void cria_pilha(pilha *p,int tam);
int push(pilha *p, brinquedo toy);
int top(pilha *p, brinquedo *toy);
int isfull_pilha(pilha *p);

#endif // PILHA_H_INCLUDED
