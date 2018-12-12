#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
typedef int elem;

typedef struct No_avl {
    elem info;
    struct No_avl *esq, *dir;
    int fb;
    int alt;
} No_avl;

typedef struct {
    No_avl *raiz;
} AVL;

void cria_avl(AVL *a);
int vazia_avl(AVL a);
int busca_avl(AVL a, elem x);
int insere_avl(AVL *a, elem x);
void E(No_avl **p);
void D(No_avl **p);
void ED(No_avl **p);
void DE(No_avl **p);
No_avl *criaNo_avl(elem info, No_avl *esq, No_avl *dir, int fb);
int maior(int x, int y);
int FB(No_avl*no);
int alt_No(No_avl*no);
int atualizaFB_avl(No_avl *p);
int remover(AVL *a, int x);
int remove_avl(No_avl **raiz, elem x);

#endif // AVL_H_INCLUDED
