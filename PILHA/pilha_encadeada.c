#include "pilha.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct pilha{
	No *topo;
	int qtdeElementos;
};



/**************************************
* FUNÇÕES AUXILIARES
**************************************/

No* novoNo(TipoElemento elemento, No* proximo){
	No* novo = (No*)malloc(sizeof(No));
	novo->dado = elemento;
	novo->prox = proximo;
	return novo;
}

bool pilha_valida(Pilha* p){
    return p != NULL;    
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Pilha* pilha_criar(){
	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
	pilha->topo = NULL;
	pilha->qtdeElementos =  0;
	return pilha;
}
void pilha_destruir(Pilha** endereco){
	if (*endereco == NULL) return;

	Pilha* p = *endereco;
	No* aux;
	while(p->topo != NULL){
		aux = p->topo->prox;
		free(p->topo);
		p->topo = aux;
	}
	free(p);
	*endereco = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
	if(!pilha_valida(p)) return false;

	No* no = novoNo(elemento, p->topo);
	no->prox = p->topo;
	p->topo = no;
	p->qtdeElementos++; 

	return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;
    if(pilha_vazia(p)) return false;

	No* noRemovido = p->topo;
	p->topo = p->topo->prox;

	*saida = noRemovido->dado;
	free(noRemovido);
	return true;
}

bool pilha_topo(Pilha* p, TipoElemento* saida){
	if(!pilha_valida(p)) return false;
    if(pilha_vazia(p)) return false;

	*saida = p->topo->dado;
	return true;
}
bool pilha_vazia(Pilha* p){
	if(!pilha_valida(p)) return false;

	return p->topo == NULL;
}

int pilha_tamanho(Pilha* p){
	if(!pilha_valida(p)) return false;

	return p->qtdeElementos;
}

void pilha_imprimir(Pilha* p, void (*printElemento)(TipoElemento*)){
	if(!pilha_valida(p)) return;
	
	printf("[");
    No* aux = p->topo;
    while(aux != NULL){
        printf(FORMATO, aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

void imprimirNo(No* no){
	if (no == NULL) return;

	imprimirNo(no->prox);
	printf("%d", no->dado);
}

void pilha_imprimirRecursivo(Pilha* p){
	imprimirNo(p->topo);
}

bool pilha_toString(Pilha* p, char* str){
	if (!pilha_valida(p)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    No* aux = p->topo;
    while(aux != NULL){    
        sprintf(elemento,FORMATO, aux->dado);
        strcat(str, elemento);
        if (aux->prox != NULL) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}

Pilha* pilha_clone(Pilha* p){
	if(!pilha_valida(p)) return NULL;

    Pilha* clone = pilha_criar();
    No* aux = p->topo;
    while(aux != NULL){
        pilha_empilhar(clone, aux->dado);
        aux = aux->prox;
    }
    pilha_inverter(clone);
    return clone;
}

void pilha_inverter(Pilha* p){
	if(!pilha_valida(p)) return;
    if(pilha_vazia(p)) return;

    Pilha* pilhaAux = pilha_criar();

    TipoElemento elemento = -1;
    while(!pilha_vazia(p)){
        pilha_desempilhar(p, &elemento);
        pilha_empilhar(pilhaAux, elemento);
    }
    p->topo = pilhaAux->topo;
    p->qtdeElementos = pilhaAux->qtdeElementos;
    free(pilhaAux);
}


bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
	if(!pilha_valida(p)) return false;

    int i;
    for(i=0; i < tamVetor ; i++){
        pilha_empilhar(p, vetor[i]);
    }
    return true;
}