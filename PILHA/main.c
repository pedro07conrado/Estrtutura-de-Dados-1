#include <stdio.h>
#include "pilha.h"



int main(){
    char str[500];

    Pilha* p = pilha_criar();
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);

    pilha_toString(p, str);
    printf("%s\n", str);
    
    


     



}