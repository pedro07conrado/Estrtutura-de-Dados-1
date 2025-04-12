#include <iostream>
using namespace std;

// typedef struct no {
//     int dado;
//     struct no* prox;
// } No;

class No {
  public:
   int dado;
   No* prox;

   No() {}
   No(int dado) { this->dado = dado; }
   No(int dado, No* prox) {
      this->dado = dado;
      this->prox = prox;
   }
};

void printEncadeada(No* no) {

   No* tmp = no;

   cout << "[";
   while (tmp != nullptr) {
      cout << tmp->dado;
      tmp = tmp->prox;
      if (tmp != nullptr) cout << ",";
   }
   cout << "]" << endl;
}

void printContigua(int* v, int tam) {
   cout << "[";
   for (int i = 0; i < tam; i++) {
      cout << v[i];
      if (i < tam - 1) cout << ",";
   }
   cout << "]" << endl;
}

int main() {

   int* organizacaoContigua = new int[10];
   organizacaoContigua[0] = 1;
   organizacaoContigua[1] = 2;
   organizacaoContigua[2] = 3;

   //    No* n1 = (No*) malloc(sizeof(No));
   //    No* n2 = (No*) malloc(sizeof(No));
   //    No* n3 = (No*) malloc(sizeof(No));

   No* n1 = new No(1);
   No* n2 = new No();
   No* n3 = new No(3, nullptr);

   //    n1->dado = 1;
   n2->dado = 2;
   //   n3->dado = 3;

   n1->prox = n2;
   n2->prox = n3;
   //    n3->prox = nullptr;

   n3->prox = new No();
   n3->prox->dado = 4;
   n3->prox->prox = nullptr;

   No* organizacaoEncadeada = n1;
   n1 = nullptr;
   n2 = nullptr;
   n3 = nullptr;

   printContigua(organizacaoContigua, 3);
   printEncadeada(organizacaoEncadeada);
}