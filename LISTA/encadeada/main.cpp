#include <iostream>
#include <string>
#include "listaEncadeada.cpp"

void teste_push_back() {
   ListaEncadeada* lista = new ListaEncadeada();
   lista->push_back(10);
   lista->push_back(20);
   lista->push_back(30);

   lista->print();  // [10,20,30]
   lista->printInverso();
}

void teste_push_front() {
   ListaEncadeada* lista = new ListaEncadeada();
   lista->push_front(10);
   lista->print();  // [10]

   lista->push_front(20);
   lista->print();  // [20,10]

   lista->push_front(30);
   lista->print();  // [30,20,10]

   lista->printInverso();  // [10,20,30]
}

void teste_insert() {
   ListaEncadeada* lista = new ListaEncadeada();

   lista->insert(0, 10);
   printf("(%d) ", lista->size());
   lista->print();  // [10]

   lista->insert(1, 20);
   printf("(%d) ", lista->size());
   lista->print();  // [10,20]

   lista->insert(2, 30);
   printf("(%d) ", lista->size());
   lista->print();  // [10,20,30]

   lista->insert(0, 5);
   printf("(%d) ", lista->size());
   lista->print();  // [5,10,20,30]

   lista->insert(1, 7);
   printf("(%d) ", lista->size());
   lista->print();  // [5,7,10,20,30]

   lista->insert(3, 15);
   printf("(%d) ", lista->size());
   lista->print();  // [5,7,10,20,30]

   lista->printInverso();  // []
}

void teste_pop_front() {
   ListaEncadeada* lista = new ListaEncadeada();
   lista->push_back(10);
   lista->push_back(20);
   lista->push_back(30);

   lista->print();  // [10,20,30]
   int valor = 0;

   valor = lista->pop_front();
   printf("Removido: (%d) ", valor);
   lista->print();

   valor = lista->pop_front();
   printf("Removido: (%d) ", valor);
   lista->print();

   valor = lista->pop_front();
   printf("Removido: (%d) ", valor);
   lista->print();

   valor = lista->pop_front();
   if (valor == -999999) {
      printf("Não foi possível remover o primeiro elemento\n");

   } else {
      printf("Removido: (%d) ", valor);
      lista->print();
   }
}

void teste_pop_back() {
   ListaEncadeada* lista = new ListaEncadeada();
   lista->push_back(10);
   lista->push_back(20);
   lista->push_back(30);

   lista->print();  // [10,20,30]
   int valor = 0;

   valor = lista->pop_back();
   printf("Removido: (%d) ", valor);  // Removido: (30)
   lista->print();                    // [10,20]

   valor = lista->pop_back();
   printf("Removido: (%d) ", valor);  // Removido: (20)
   lista->print();                    // [10]

   valor = lista->pop_back();
   printf("Removido: (%d) ", valor);  // Removido: (10)
   lista->print();                    // []

   valor = lista->pop_back();
   if (valor == LISTA_VAZIA) {
      printf("Não foi possível remover o último elemento\n");

   } else {
      printf("Removido: (%d) ", valor);
      lista->print();
   }
}

int main() {
   teste_push_back();
   // teste_push_front();
   // teste_insert();
   // teste_pop_front();
   // teste_pop_back();
}