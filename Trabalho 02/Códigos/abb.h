#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
typedef int elem;

typedef struct no_abb {
    elem info;
    struct no_abb *esq, *dir;
} No_abb;

typedef struct {
    No_abb *raiz;
} ABB;

void cria_abb(ABB *a);
int busca_abb(ABB a, elem x);
int insere_abb(ABB *a, elem x);
int remover_abb(ABB *a, elem x);
void destroi_abb(ABB *a);


#endif // ABB_H_INCLUDED
