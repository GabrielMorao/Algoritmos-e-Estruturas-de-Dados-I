#ifndef PILHA_C_INCLUDED
#define PILHA_C_INCLUDED
#include <stdlib.h>
#include "pilha.h"

int isfull_pilha(pilha *p){
    if(p->num_elementos >= p->tam_caixa){
        return 1;
    }
    return 0;
}

void cria_pilha(pilha *p,int tam){
    p->tam_caixa = tam;
    p->vet = malloc(sizeof(brinquedo)*p->tam_caixa);
    p->topo = -1;
    p->num_elementos = 0;
}

int push(pilha *p, brinquedo toy){
    if (p->topo == p->tam_caixa-1){
        return 1; //Em caso de a pilha estar cheia, apresenta erro 1.
    }
    p->topo++;
    p->vet[p->topo] = toy;
    p->num_elementos++;

    return 0;
}

int top(pilha *p, brinquedo *toy){
    if(p->topo == -1){
        return 1;
    }
    *toy = p->vet[p->topo];
    return 0;
}


#endif // PILHA_C_INCLUDED
