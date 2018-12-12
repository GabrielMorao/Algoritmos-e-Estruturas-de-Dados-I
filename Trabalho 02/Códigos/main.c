#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*

    Serão incluidas 6 TAD'S sendo eles de Busca Binária(bb.h),
Lista Ordenada(lo.h), Lista Ordenada com sentinela(los.h), Árvore Binaria
de Busca(abb.h), Árvore AVL(avl.h) e  Lista circular dinâmica duplamente encadeada,
organizada pela frequência de busca(lfreq.h).
    Cada uma dessas bibliotecas contem as funções de inserção, remoção
e busca para a respectiva estrutura.

 */
#include "lo.h"
#include "los.h"
#include "abb.h"
#include "avl.h"
#include "busca_bin.h"
#include "lfreq.h"

/*Variaveis representando as tabelas, serão inciadas com 0 automáticamente*/

    double insercao_c[6][4];
    double insercao_d[6][4];
    double insercao_r[6][4];
    double busca_c[6][4];
    double busca_d[6][4];
    double busca_r[6][4];
    double remocao_c[6][4];
    double remocao_dc[6][4];
    double remocao_r[6][4];

int main()
{
    clock_t tempo = 0;
    double res_tempo = 0;
    vetor_busca vbb;
    ListaOrd lo;
    ListaOrdSent los;
    ABB arvbb;
    AVL arvavl;
    Listad lfreq;
    int linha = 0;
    int coluna = 0;
    //================================================================================================================//
        //ORDEM CRESCENTE
    //================================================================================================================//
    //BB
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //busca binaria cresc - insere
        cria_vetor_busca_bin(&vbb,n);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_busca_bin(&vbb,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //busca binaria cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_binaria(&vbb,rand()%n);
            }
            else{
            busca_binaria(&vbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //busca binaria cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_busca_bin(&vbb,j);
            }
            else{
            remover_busca_bin(&vbb,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LO
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lo cresc - insere
        cria_lista_lo(&lo);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_lo(&lo,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //lo cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_lo(lo,(rand()%n));
            }
            else{
            busca_lo(lo,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //lo cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_lo(&lo,j);
            }
            else{
            remover_lo(&lo,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LOS
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //los cresc - insere
        cria_los(&los);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_los(&los,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //los cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_los(los,(rand()%n));
            }
            else{
            busca_los(los,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //los cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            remover_los(&los,j);
            else
            remover_los(&los,j+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //ABB
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //abb cresc - insere
        cria_abb(&arvbb);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_abb(&arvbb,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //abb cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            busca_abb(arvbb,(rand()%n));
            else{
            busca_abb(arvbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //abb cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            remover_abb(&arvbb,j);
            else
            remover_abb(&arvbb,j+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //AVL
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //avl cresc - insere
        cria_avl(&arvavl);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_avl(&arvavl,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //avl cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_avl(arvavl,(rand()%n));
            }

            else{
            busca_avl(arvavl,(rand()%n)+n);
            }

        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //avl cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover(&arvavl,j);
            }
            else{
            remover(&arvavl,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LFREQ
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lfreq cresc - insere
        cria_lista_lfreq(&lfreq);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_lfreq(&lfreq,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_c[linha][coluna] += res_tempo/10;
        //lfreq cresc - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            busca_lfreq(&lfreq,(rand()%n));
            else
            busca_lfreq(&lfreq,(rand()%n)+n);
        }
        //imprime(lfreq);
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_c[linha][coluna] += res_tempo/10;
        //lfreq cresc - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_lfreq(&lfreq,j);
            }
            else{
            remover_lfreq(&lfreq,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_c[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
        //INSERE DECRESCENTE BUSCA CRESCENTE
    //================================================================================================================//
    //BB
	linha = 0;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //busca binaria decresc - insere
        cria_vetor_busca_bin(&vbb,n);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_busca_bin(&vbb,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //busca binaria decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j>=n/2){
            busca_binaria(&vbb,rand()%n);
            }
            else{
            busca_binaria(&vbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LO
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lo decresc - insere
        cria_lista_lo(&lo);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_lo(&lo,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //lo decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j>=n/2)
            busca_lo(lo,(rand()%n));
            else
            busca_lo(lo,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LOS
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //los decresc - insere
        cria_los(&los);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_los(&los,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //los decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j>=n/2)
            busca_los(los,(rand()%n));
            else
            busca_los(los,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //ABB
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //abb decresc - insere
        cria_abb(&arvbb);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_abb(&arvbb,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //abb decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j>=n/2)
            busca_abb(arvbb,(rand()%n));
            else
            busca_abb(arvbb,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //AVL
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //avl decresc - insere
        cria_avl(&arvavl);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_avl(&arvavl,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //avl decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j>=n/2)
            busca_avl(arvavl,(rand()%n));
            else
            busca_avl(arvavl,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LFREQ
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lfreq decresc - insere
        cria_lista_lfreq(&lfreq);
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            insere_lfreq(&lfreq,j);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_d[linha][coluna] += res_tempo/10;
        //lfreq decresc - busca
        tempo = clock();
        for(int j=n-1; j>=0; j--){
            if(j<n/2)
            busca_lfreq(&lfreq,(rand()%n));
            else
            busca_lfreq(&lfreq,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_d[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
        //ORDEM ALEATORIA
    //================================================================================================================//
    //BB
	linha = 0;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //busca binaria RAND - insere
        cria_vetor_busca_bin(&vbb,n);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_busca_bin(&vbb,rand()%n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //busca binaria RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_binaria(&vbb,rand()%n);
            }
            else{
            busca_binaria(&vbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //busca binaria RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_busca_bin(&vbb,rand()%n);
            }
            else{
            remover_busca_bin(&vbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LO
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lo RAND - insere
        cria_lista_lo(&lo);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_lo(&lo,(rand()%n));
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //lo RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_lo(lo,(rand()%n));
            }
            else{
            busca_lo(lo,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //lo RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_lo(&lo,(rand()%n));
            }
            else{
            remover_lo(&lo,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LOS
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //los RAND - insere
        cria_los(&los);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_los(&los,(rand()%n));
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //los RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_los(los,(rand()%n));
            }
            else{
            busca_los(los,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //los RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            remover_los(&los,(rand()%n));
            else
            remover_los(&los,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //ABB
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //abb RAND - insere
        cria_abb(&arvbb);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_abb(&arvbb,(rand()%n));
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //abb RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            busca_abb(arvbb,(rand()%n));
            else{
            busca_abb(arvbb,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //abb RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            remover_abb(&arvbb,(rand()%n));
            else
            remover_abb(&arvbb,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //AVL
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //avl RAND - insere
        cria_avl(&arvavl);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_avl(&arvavl,(rand()%n));
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //avl RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            busca_avl(arvavl,(rand()%n));
            }
            else{
            busca_avl(arvavl,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //avl RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover(&arvavl,j);
            }
            else{
            remover(&arvavl,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LFREQ
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lfreq RAND - insere
        cria_lista_lfreq(&lfreq);
        tempo = clock();
        for(int j=0; j<n; j++){
            insere_lfreq(&lfreq,(rand()%n));
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        insercao_r[linha][coluna] += res_tempo/10;
        //lfreq RAND - busca
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2)
            busca_lfreq(&lfreq,(rand()%n));
            else
            busca_lfreq(&lfreq,(rand()%n)+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        busca_r[linha][coluna] += res_tempo/10;
        //lfreq RAND - remoçao
        tempo = clock();
        for(int j=0; j<n; j++){
            if(j<n/2){
            remover_lfreq(&lfreq,(rand()%n));
            }
            else{
            remover_lfreq(&lfreq,(rand()%n)+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_r[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
        //INSERE CRESCENTE E REMOVE DECRESCENTE
    //================================================================================================================//
    //BB
	linha = 0;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //busca binaria cresc - insere
        cria_vetor_busca_bin(&vbb,n);
        for(int j=0; j<n; j++){
            insere_busca_bin(&vbb,j);
        }
        //busca binaria cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j<n/2){
            remover_busca_bin(&vbb,j);
            }
            else{
            remover_busca_bin(&vbb,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LO
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lo cresc - insere
        cria_lista_lo(&lo);
        for(int j=0; j<n; j++){
            insere_lo(&lo,j);
        }
        //lo cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j>=n/2){
            remover_lo(&lo,j);
            }
            else{
            remover_lo(&lo,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LOS
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //los cresc - insere
        cria_los(&los);
        for(int j=0; j<n; j++){
            insere_los(&los,j);
        }
        //los cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j>=n/2)
            remover_los(&los,j);
            else
            remover_los(&los,j+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //ABB
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //abb cresc - insere
        cria_abb(&arvbb);
        for(int j=0; j<n; j++){
            insere_abb(&arvbb,j);
        }
        //abb cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j>=n/2)
            remover_abb(&arvbb,j);
            else
            remover_abb(&arvbb,j+n);
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //AVL
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //avl cresc - insere
        cria_avl(&arvavl);
        for(int j=0; j<n; j++){
            insere_avl(&arvavl,j);
        }
        //avl cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j>=n/2){
            remover(&arvavl,j);
            }
            else{
            remover(&arvavl,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}
    //================================================================================================================//
    //LFREQ
	linha++;
    for(int i=0; i<10; i++){
    coluna = 0;
    for(int n=100; n<=100000; n*=10){
        //lfreq cresc - insere
        cria_lista_lfreq(&lfreq);
        for(int j=0; j<n; j++){
            insere_lfreq(&lfreq,j);
        }
        //lfreq cresc - remoçao
        tempo = clock();
        for(int j=n; j>=0; j--){
            if(j>=n/2){
            remover_lfreq(&lfreq,j);
            }
            else{
            remover_lfreq(&lfreq,j+n);
            }
        }
        res_tempo = (double)(clock()-tempo)/CLOCKS_PER_SEC;
        remocao_dc[linha][coluna] += res_tempo/10;
        coluna++;
    }
}

//print das tabelas em si
    printf("Tabela 1: Tempo de insercao crescente\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",insercao_c[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 2: Tempo de insercao decrescente\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",insercao_d[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 3: Tempo de insercao aleatoria\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",insercao_r[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 4: Tempo de remocao crescente (apos insercao crescente)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",remocao_c[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 5: Tempo de remocao decrescente (apos insercao crescente)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",remocao_dc[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 6: Tempo de remocao aleatoria (apos insercao aleatoria)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",remocao_r[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 7: Tempo de busca (apos insercao crescente)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",busca_c[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 8: Tempo de busca (apos insercao decrescente)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",busca_d[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    printf("Tabela 9: Tempo de busca (apos insercao aleatoria)\n");
    printf("\tn=100\tn=1.000\tn=10.000\tn=100.000\n");
    for(int j=0; j<6; j++){
        switch(j){
        case 0 :
            printf("BB");
            break;
        case 1 :
            printf("LO");
            break;
        case 2 :
            printf("LOS");
            break;
        case 3 :
            printf("ABB");
            break;
        case 4 :
            printf("AVL");
            break;
        case 5 :
            printf("LFREQ");
            break;
        }
        for(int i=0; i<4; i++){
            printf("\t%lf",busca_r[j][i]);
        }
        printf("\n");
    }
    printf("-\n");
    return 0;
}
