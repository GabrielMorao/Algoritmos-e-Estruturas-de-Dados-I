#include <stdlib.h>
#include <stdio.h>
#include "los.h"

int cria_los(ListaOrdSent *l) {
    l->sentinela = malloc(sizeof(No_los));
    if (l->sentinela == NULL)
        return 1; // erro, memoria insificiente
    l->sentinela->prox = NULL;
    l->ini = l->sentinela;
    return 0;
}

void busca_interna_los(ListaOrdSent *l, elem x, No_los **ant, No_los **p) {
    // ant, p => No **
    // *ant, *p => No *
    // **ant, **p => No
    l->sentinela->info = x; // forca parada na busca
    *p = l->ini;
    *ant = NULL;
    while ((*p)->info < x) {
        *ant = *p;
        *p = (*p)->prox;
    }
    return;
}

int insere_los(ListaOrdSent *l, elem x) {
    No_los *novo, *p, *ant;
    busca_interna_los(l, x, &ant, &p);
    if (p != l->sentinela && p->info == x)
        return 1; // erro, já existe
    novo = malloc(sizeof(No_los));
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

int remover_los(ListaOrdSent *l, elem x) {
    No_los *ant, *p;
    busca_interna_los(l, x, &ant, &p);
    if (p == l->sentinela || p->info != x)
        return 1; // erro, nao achou
    if (p == l->ini) // outra possibilidade if (ant == NULL)
        l->ini = p->prox; // remove do inicio
    else
        ant->prox = p->prox; // remove do meio ou final
    free(p);
    return 0; // sucesso, achou e removeu
}

int busca_los(ListaOrdSent l, elem x) {
    l.sentinela->info = x; // forca parada
    while (l.ini->info < x)
        l.ini = l.ini->prox;
    return (l.ini != l.sentinela && l.ini->info == x);
}
