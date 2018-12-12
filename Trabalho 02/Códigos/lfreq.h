#ifndef LFREQ_H_INCLUDED
#define LFREQ_H_INCLUDED
typedef int elem;

typedef struct No {
    elem info;
    struct No *ant, *prox;
    int num_busca;
} No_lfreq;

typedef struct {
    No_lfreq *ini, *fim;
    int tam_lista;
} Listad;

void cria_lista_lfreq(Listad *l);
int insere_lfreq(Listad *l, elem x);
int busca_lfreq(Listad *l, elem x);
int remover_lfreq(Listad *l, elem x);

#endif // LFREQ_H_INCLUDED
