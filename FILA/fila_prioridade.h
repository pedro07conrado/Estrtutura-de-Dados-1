#ifndef _FILA_PRIORIDADE_H_
#define _FILA_PRIORIDADE_H_

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define FORMATO "%d"
typedef  int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct _filaPrioridade FilaPrioridade;


/**************************************
* PROTÓTIPOS
**************************************/
FilaPrioridade* filaP_criar();
void filaP_destruir(FilaPrioridade** enderecoFila);
bool filaP_inserir(FilaPrioridade* f, TipoElemento elemento);
bool filaP_remover(FilaPrioridade* f, TipoElemento* saida); // estratégia do scanf
bool filaP_primeiro(FilaPrioridade* f, TipoElemento* saida); // estratégia do scanf
bool filaP_vazia(FilaPrioridade* f);
int filaP_tamanho(FilaPrioridade* f);
FilaPrioridade* filaP_clone(FilaPrioridade* f);
bool filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor);
bool filaP_toString(FilaPrioridade* f, char* str);




#endif