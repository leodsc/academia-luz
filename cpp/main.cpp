#include <iostream>
#include "lib.hpp"
using namespace std;

void log(string s) {
  cout << s << endl;
}

void nodeMenu() {
  log("Adicionando três nós com valores 10, 50 e 60");
  Node *c1 = new Node(10);
  Node *c2 = new Node(50);
  Node *c3 = new Node(60);
  c1->print();

  log("Linkando primeiro nó (10) ao segundo (50)");
  *c1 + c2;
  log("Linkando segundo nó (50) ao terceiro (60)");
  *c2 + c3;
  c1->print();

  log("Removendo ligação do primeiro nó com o segundo");
  c1->remove();
  c1->print();

  log("Removendo ligação do primeiro nó com o último");
  c1->remove();
  c1->print();
}

void stackMenu() {
  int v;
  Stack *stack = new Stack();

  stack->print();

  log("Adicionando 4 nós com valores 500, 300, 400 e 200 à pilha");
  stack->push(500);
  stack->push(300);
  stack->push(400);
  stack->push(200);
  stack->print();

  log("removendo...");
  v = stack->pop();
  cout << "valor " << v << " removido" << endl;
  stack->print();

  log("removendo...");
  v = stack->pop();
  cout << "valor " << v << "removido" << endl;
  stack->print();

  log("Adicionando valor 900");
  stack->push(900);
  stack->print();
}

void queueMenu() {
  Queue *queue = new Queue();
  int v;

  queue->print();
  log("Adicionando 3 valores: 500, 100 e 200");
  queue->push(500);
  queue->push(100);
  queue->push(200);
  queue->print();

  v = queue->unshift();
  cout << "Removido primero valor: " << v << endl;
  queue->print();

  log("Adiconando valor 300");
  queue->push(300);
  queue->print();
}

void linkedListMenu() {
  LinkedList *linkedList = new LinkedList();
  linkedList->print();

  linkedList->push(100);
  linkedList->push(200);
  linkedList->push(300);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(1);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(0);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(0);
  linkedList->print();

  linkedList->push(500);
  cout << "ADDED..." << endl;
  linkedList->print();
}

void menu() {
  int choice;
  do {
    log("Escolha uma opção abaixo: ");
    log("1 - Nodes");
    log("2 - Stack");
    log("3 - Queue");
    log("4 - Linked List");
    log("0 - Sair");
    cin >> choice;

    switch (choice) {
      case 1: nodeMenu(); break;
      case 2: stackMenu(); break;
      case 3: queueMenu(); break;
      case 4: linkedListMenu(); break;
    }
  } while (choice != 0);
}

int main() {
  menu();
  return 0;
};
