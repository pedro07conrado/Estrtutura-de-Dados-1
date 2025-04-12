#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "tad_timer.h"


typedef unsigned long int Inteiro;

Inteiro* criaVetorOrdenado(Inteiro n){
    Inteiro * vetor = (Inteiro*) calloc(n, sizeof(Inteiro));
    for (Inteiro i=0; i < n; i++){
        vetor[i] = i;
    }
    return vetor;
}



Inteiro* criaVetorAleatorio(Inteiro n){
    Inteiro * vetor = (Inteiro*) calloc(n, sizeof(Inteiro));
    srand(time(NULL));
    for (Inteiro i=0; i < n; i++){
        vetor[i] = rand() % (8 * n);
    }
    return vetor;
}

void imprimeVetor(long int* v, long int tam){
    printf("[");
    for (long int i=0; i < tam; i++){
        printf("%ld", v[i]);
        if (i < tam-1) printf(",");
    }
    printf("]");
    printf("\n");
}

Inteiro buscaSequencial(Inteiro* v, Inteiro tam, Inteiro elemento){
    Inteiro i;
    for (i=0; i < tam; i++){
        if (elemento == v[i]) return i;
    }
    
    return -1;
}

Inteiro buscaBinaria(Inteiro* v, Inteiro tam, Inteiro elemento){
    Inteiro inicio = 0;
    Inteiro fim = tam-1;
    Inteiro meio;

    while (inicio <= fim){
        meio = inicio + ( (fim - inicio) / 2 );
        if (elemento == v[meio]){
            return meio;
        } else if (elemento < v[meio]){
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

void executaCarga(int carga){
    for (int i=0; i < carga; i++);
}


Inteiro ordem_n(Inteiro n, int carga){
    
    Inteiro comparacoes = 0;
    for (Inteiro i=0; i < n; i++){
        executaCarga(carga);
        comparacoes++;
    }
    return comparacoes;

}

Inteiro ordem_NlogN(Inteiro n, int carga){
    
    Inteiro tam;
    Inteiro comparacoes = 0;
    for (Inteiro i=0; i < n; i++){
        tam = n;
        while (tam > 0){
            executaCarga(carga);
            comparacoes++;

            tam = tam / 2;
        }    
    }
    return comparacoes;

}
Inteiro ordem_n2(Inteiro n, int carga){

    
    
    Inteiro comparacoes = 0;
    for (Inteiro i=0; i < n; i++){
        for (Inteiro j=0; j < n; j++){
            executaCarga(carga);
            comparacoes++;
        }
    }
    return comparacoes;

}

Inteiro ordem_logN(Inteiro n, int carga){
    
    Inteiro comparacoes = 0;
    while (n > 0){
        executaCarga(carga);
        comparacoes++;

        n = n / 2;
    }
    return comparacoes;

}




int main(){
    Inteiro qtdComparacoes = 0;
    clock_t inicio, fim;
    double tempo;

    int carga = 10;
    Inteiro n = 1000;


    printf("Tamanho entrada: %lu\n\n", n);

    
    /***********************************************
    * O(log n)
    ************************************************/
    printf("O(log n)\n");
    
    inicio = clock();
    qtdComparacoes = ordem_logN(n, carga);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Comparacoes: %lu\n", qtdComparacoes);
    printf("Tempo: %f\n\n", tempo);

    /***********************************************
    * O(n)
    ************************************************/
    printf("O(n)\n");
    
    inicio = clock();
    qtdComparacoes = ordem_n(n, carga);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Comparacoes: %lu\n", qtdComparacoes);
    printf("Tempo: %f\n\n", tempo);


    /***********************************************
    * O(n log n)
    ************************************************/
    printf("O(n log n)\n");
    
    inicio = clock();
    qtdComparacoes = ordem_NlogN(n, carga);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Comparacoes: %lu\n", qtdComparacoes);
    printf("Tempo: %f\n\n", tempo);

    /***********************************************
    * O(n2)
    ************************************************/
    printf("O(n2)\n");
    
    inicio = clock();
    qtdComparacoes = ordem_n2(n, carga);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Comparacoes: %lu\n", qtdComparacoes);
    printf("Tempo: %f\n\n", tempo);
    

    return 0;
}