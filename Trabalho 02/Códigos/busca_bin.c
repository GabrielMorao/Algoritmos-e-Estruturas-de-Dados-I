#include <stdlib.h>
#include <stdio.h>
#include "busca_bin.h"

int cria_vetor_busca_bin(vetor_busca* vet,int n){
    vet->tam_vet = n;
    vet->total_elems = 0;
    vet->vetor_busca_bin = (int*)malloc(n*sizeof(int));
    if(vet->vetor_busca_bin == NULL){
        return 1;
    }
    return 0;
}

int insere_busca_bin(vetor_busca* vet,int numero){
    /*no caso posição será i, ele sempre inserirá na ultima posição, depois será usado o insertion sort para inserir o vetor
na posição correta*/
    if(vet->total_elems < vet->tam_vet){
        vet->total_elems++;
        vet->vetor_busca_bin[vet->total_elems-1] = numero;
        //chamada do insertion sort
        insertion_sort(vet);
        return 0;
    }
    return 1;   //erro, posição inválida
}

void insertion_sort(vetor_busca* vet){
    for(int i=1; i<vet->total_elems; i++){
        int tmp = vet->vetor_busca_bin[i];
        int k = i-1;
        while(vet->vetor_busca_bin[k] > tmp && k>=0){
            vet->vetor_busca_bin[k+1] = vet->vetor_busca_bin[k];
            k--;
        }
        vet->vetor_busca_bin[k+1] = tmp;
    }
}

int busca_binaria(vetor_busca* vet,int numero){
    //retorna a posicao que achou ou -1 se nao achou
    int comeco=0;
    int fim = vet->total_elems-1;
    int meio;
    while(comeco <= fim){
        meio = (fim + comeco)/2;
        //printf("%d\n",meio);
        if(numero > vet->vetor_busca_bin[meio]){
            comeco = meio+1;
        }
        else if(numero < vet->vetor_busca_bin[meio]){
            fim = meio-1;
        }
        else{
            return meio;
        }
    }
    return -1;
}

int remover_busca_bin(vetor_busca* vet,int numero){
    int pos = busca_binaria(vet,numero);
    if(pos == -1){
        return 0;//nao achou
    }
    int k = pos;
    while(k<vet->total_elems-1){
        k++;
        vet->vetor_busca_bin[k-1] = vet->vetor_busca_bin[k];
    }
    vet->total_elems--;
    return 1;
}
