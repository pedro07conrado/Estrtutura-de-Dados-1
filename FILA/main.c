#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "fila_prioridade.h"

int main(){
    
    int n = 50000;
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));

    FilaPrioridade* f = filaP_criar();
    printf("Insercao\n");
    inicio = clock();
    for (int i=0; i < n; i++){
        filaP_inserir(f, rand() % n);
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo: %.2f\n\n", tempo);
        


    return 0;
}