#include <stdlib.h>
#include <stdio.h>
#include "lo.h"

void cria_lista_lo(ListaOrd *l) {
    l->ini = NULL;
    return;
}

void busca_interna_lo(ListaOrd *l, elem x, No **ant, No **p) {
    // ant, p => No **
    // *ant, *p => No *
    // **ant, **p => No
    *p = l->ini;
    *ant = NULL;
    while (*p != NULL && (*p)->info < x) {
        *ant = *p;
        *p = (*p)->prox;
    }
    return;
}

int insere_lo(ListaOrd *l, elem x) {
    No *novo, *p, *ant;
    busca_interna_lo(l, x, &ant, &p);
    if (p != NULL && p->info == x)
        return 1; // erro, já existe
    novo = (No *) malloc(sizeof(No));
    if (novo == NULL)
        return 1; // erro, memoria insuficiente
    novo->info = x;
    novo->prox = p;
    if (p == l->ini) // outra possibilidade if (ant == NULL)
        l->ini = novo; // insere no inicio, caso 1
    else
        ant->prox = novo; // insere no meio ou final, caso 2
    return 0; // sucesso
}

int remover_lo(ListaOrd *l, elem x) {
    No *ant, *p;
    busca_interna_lo(l, x, &ant, &p);
    if (p == NULL || p->info != x)
        return 1; // erro, nao achou
    if (p == l->ini) // outra possibilidade if (ant == NULL)
        l->ini = p->prox; // remove do inicio
    else
        ant->prox = p->prox; // remove do meio ou final
    free(p);
    return 0; // sucesso, achou e removeu
}

int busca_lo(ListaOrd l, elem x) {
    while (l.ini != NULL && l.ini->info < x)
        l.ini = l.ini->prox;
    return (l.ini != NULL && l.ini->info == x);
}


