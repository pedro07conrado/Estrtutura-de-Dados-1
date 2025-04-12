#include "fila_prioridade.h"
#include <string.h>

#define TAM_INICIAL 100000000


/**************************************
* DADOS
**************************************/
struct _filaPrioridade{
    TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
bool fila_ehValida(FilaPrioridade* f){
    return (f != NULL? true : false);
}

void realoca(FilaPrioridade* f, int novoTamanho){
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for(i = 0; i < f->qtdeElementos; i++) vetorAuxiliar[i] = f->vetor[i];
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    f->tamVetor = novoTamanho;
}

void verifica_aumenta(FilaPrioridade* f){
    if(f->qtdeElementos == f->tamVetor){
        realoca(f, f->tamVetor*2);
    }
}

void verifica_diminui(FilaPrioridade* f){
    if (f->qtdeElementos <= f->tamVetor / 4 && f->tamVetor > TAM_INICIAL){
        realoca(f, f->tamVetor/2);
    }
}


int pai(int i){
    return (i-1)/2;
}

int filhoEsquerda(int i){
    return 2 * i + 1;
}

int filhoDireita(int i){
    return 2 * i + 2;
}

void troca(TipoElemento* a, TipoElemento* b){
    TipoElemento tmp = *a;
    *a = *b;
    *b = tmp;
}

void sobe_ajustando(FilaPrioridade* f, int k){
    while(k > 0 && f->vetor[k] > f->vetor[pai(k)]){
        troca(&f->vetor[k], &f->vetor[pai(k)]);
        k = pai(k);
    }
}

bool temFilhoEsquerda(FilaPrioridade* f, int k){
    return (filhoEsquerda(k) < f->qtdeElementos);
}
bool temFilhoDireita(FilaPrioridade* f, int k){
    return (filhoDireita(k) < f->qtdeElementos);
}

//testar
int devolveMaiorFilho(FilaPrioridade* f, int k){    
    if(!temFilhoEsquerda(f, k)) return -1;
    
    int maior = filhoEsquerda(k);
    if(temFilhoDireita(f, k)){
        if(f->vetor[filhoDireita(k)] > f->vetor[filhoEsquerda(k)])
            maior = filhoDireita(k);
    }
    return maior;
}



void desce_ajustando(FilaPrioridade* f, int k){
    int posMaiorFilho = devolveMaiorFilho(f, k);
    
    while(posMaiorFilho != -1){ // enquanto tiver filhos
        // se o maior filho for maior que o pai, troca e continua descendo
        if(f->vetor[posMaiorFilho] > f->vetor[k]){
            troca(&f->vetor[k], &f->vetor[posMaiorFilho]);
            k = posMaiorFilho;
            posMaiorFilho = devolveMaiorFilho(f, k);
        // caso contrário, a posicao está correta
        }else{
            posMaiorFilho = -1;
        }
    }
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

FilaPrioridade* filaP_criar(){
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    return f;
}

void filaP_destruir(FilaPrioridade** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    FilaPrioridade* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool filaP_inserir(FilaPrioridade* f, TipoElemento elemento){
    // if(!fila_ehValida(f)) return false;
    // verifica_aumenta(f);

    f->vetor[f->qtdeElementos] = elemento;

    sobe_ajustando(f, f->qtdeElementos);
    f->qtdeElementos++;
    return true;


}

bool filaP_remover(FilaPrioridade* f, TipoElemento* saida){
    // if(!fila_ehValida(f)) return false;
    // if (filaP_vazia(f)) return false;
    
    *saida = f->vetor[0];

    // troca(&(f->vetor[0]), &(f->vetor[f->qtdeElementos-1]));
    f->vetor[0] = f->vetor[f->qtdeElementos-1];
    
    desce_ajustando(f, 0);
    f->qtdeElementos--;


    // verifica_diminui(f);
    return true;

}

bool filaP_primeiro(FilaPrioridade* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if (filaP_vazia(f)) return false;

    *saida = f->vetor[0];
    return true;
}

bool filaP_vazia(FilaPrioridade* f){
    if(!fila_ehValida(f)) return false;

    return (f->qtdeElementos == 0? true: false);

}
int filaP_tamanho(FilaPrioridade* f){
    if(!fila_ehValida(f)) return -1;

    return f->qtdeElementos;
}


FilaPrioridade* filaP_clone(FilaPrioridade* f){
    if(!fila_ehValida(f)) return NULL;

    FilaPrioridade* novo = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    novo->vetor = (TipoElemento*)calloc(f->tamVetor, sizeof(TipoElemento));
    memcpy(novo->vetor, f->vetor, f->qtdeElementos * sizeof(TipoElemento));
    novo->tamVetor = f->tamVetor;
    novo->qtdeElementos = f->qtdeElementos;
    return novo;
}

bool filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor){
    if(!fila_ehValida(f)) return false;
    
    int i;
    for(i=0; i < tamVetor; i++){
        filaP_inserir(f, vetor[i]);
    }
    return true;
}

bool filaP_toString(FilaPrioridade* f, char* str){
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    int i;
    for(i=0; i < f->qtdeElementos; i++){
        sprintf(elemento,FORMATO, f->vetor[i]);
        strcat(str, elemento);
        if(i < f->qtdeElementos-1) strcat(str, ",");
    }
    strcat(str, "]");
    return true;
}
