#ifndef LOS_H_INCLUDED
#define LOS_H_INCLUDED

typedef int elem;

typedef struct no_los {
    elem info;
    struct no_los *prox;
} No_los;

typedef struct {
    No_los *ini, *sentinela;
} ListaOrdSent;

int cria_los(ListaOrdSent *l);
void busca_interna_los(ListaOrdSent *l, elem x, No_los **ant, No_los **p);
int insere_los(ListaOrdSent *l, elem x);
int remover_los(ListaOrdSent *l, elem x);
int busca_los(ListaOrdSent l, elem x);



#endif // LOS_H_INCLUDED
