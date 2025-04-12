#include "pilha.h"


#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct pilha {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/

void realoca(Pilha* p, int novoTamanho){
    TipoElemento* vetorAuxiliar = (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    for(i = 0; i < p->qtdeElementos; i++) vetorAuxiliar[i] = p->vetor[i];
    free(p->vetor);
    p->vetor = vetorAuxiliar;
    p->tamVetor = novoTamanho;
}

void verifica_aumenta(Pilha* p){
    if(p->qtdeElementos == p->tamVetor){
        realoca(p, p->tamVetor*2);
    }    
}

void verifica_diminui(Pilha* p){
    if (p->qtdeElementos < p->tamVetor / 4){
        realoca(p, p->tamVetor/2);
    }    
}


bool pilha_valida(Pilha* p){	
	return p != NULL;

	// return (p==NULL ? false :true);

}


/**************************************
* IMPLEMENTAÇÃO
**************************************/


Pilha* pilha_criar(){
	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
	pilha->vetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));
	pilha->tamVetor = TAM_INICIAL;
	pilha->qtdeElementos = 0;
	return pilha;
}

void pilha_destruir(Pilha** endereco){
	if (*endereco == NULL) return;

	Pilha* p = *endereco;
	free(p->vetor);
	free(p);
	*endereco = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
	if(!pilha_valida(p)) return false;

	verifica_aumenta(p);

	p->vetor[p->qtdeElementos++] = elemento;
	return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;
    if(pilha_vazia(p)) return false;

    verifica_diminui(p);

    *saida = p->vetor[--p->qtdeElementos];
    return true;
}

bool pilha_topo(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;
    if(pilha_vazia(p)) return false;
    
    *saida = p->vetor[p->qtdeElementos-1];
    return true;
}

bool pilha_vazia(Pilha* p){
    if(!pilha_valida(p)) return false;

	return p->qtdeElementos == 0;
}
int pilha_tamanho(Pilha* p){
    if(!pilha_valida(p)) return false;
    
	return p->qtdeElementos;
}

void pilha_imprimir(Pilha* p, void (*printElemento)(TipoElemento*)){
	printf("[");
	for (int i=p->qtdeElementos-1; i >=0; i--){
		printElemento(&(p->vetor[i]));
		if(i > 0) printf(",");
	}
	printf("]");
}
bool pilha_toString(Pilha* p, char* str){
	if (!pilha_valida(p)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    int i;
    for(i = p->qtdeElementos-1; i>=0; i--){
        sprintf(elemento,FORMATO, p->vetor[i]);
        strcat(str, elemento);
        if (i>0) strcat(str, ",");
    }
    strcat(str, "]");
    return true;
}

Pilha* pilha_clone(Pilha* p){
	Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
	novo->vetor = (TipoElemento*)calloc(p->tamVetor, sizeof(TipoElemento));
	memcpy(novo->vetor, p->vetor, p->qtdeElementos * sizeof(TipoElemento));
	novo->qtdeElementos = p->qtdeElementos;
    novo->tamVetor = p->tamVetor;
	return novo;
}



void pilha_inverter(Pilha* p){
    if(!pilha_valida(p)) return;
    if(pilha_vazia(p)) return;

	int inicio = 0;
	int final = p->qtdeElementos-1;

	while(final > inicio){
		int temp = p->vetor[inicio];
		p->vetor[inicio] = p->vetor[final];
		p->vetor[final] = temp;
		inicio++;
		final--;
	}
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
	if(!pilha_valida(p)) return false;

    int i;
    for(i=0; i < tamVetor ; i++){
        pilha_empilhar(p, vetor[i]);
    }
    return true;
}