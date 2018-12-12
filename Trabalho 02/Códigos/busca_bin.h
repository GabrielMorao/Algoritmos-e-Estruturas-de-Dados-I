#ifndef BUSCA_BIN_H_INCLUDED
#define BUSCA_BIN_H_INCLUDED

typedef struct{
    int *vetor_busca_bin;
    int tam_vet;
    int total_elems;
}vetor_busca;

int cria_vetor_busca_bin(vetor_busca* vet,int n);
int insere_busca_bin(vetor_busca* vet,int numero);
void insertion_sort(vetor_busca* vet);
int busca_binaria(vetor_busca* vet,int numero);
int remover_busca_bin(vetor_busca* vet,int numero);
#endif // BUSCA_BIN_H_INCLUDED
