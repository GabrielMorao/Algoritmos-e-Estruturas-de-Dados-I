#ifndef LO_H_INCLUDED
#define LO_H_INCLUDED
typedef int elem;

typedef struct no {
    elem info;
    struct no *prox;
} No;

typedef struct {
    No *ini;
} ListaOrd;

void cria_lista_lo(ListaOrd *l);
void busca_interna_lo(ListaOrd *l, elem x, No **ant, No **p);
int insere_lo(ListaOrd *l, elem x);
int remover_lo(ListaOrd *l, elem x);
int busca_lo(ListaOrd l, elem x);

#endif // LO_H_INCLUDED
