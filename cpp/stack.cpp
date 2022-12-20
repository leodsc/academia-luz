#include <iostream>
#include "stack.hpp"

Stack::Stack() {
  this->size = 0;
};

Node* Stack::top() {
  if (this->size == 0) {
    return NULL;
  }
  return this->head;
};

void Stack::push(int value) 
{
  Node *node = new Node(value);
  if (this->size == 0)
  {
    this->head = node;
  } 
  else
  {
    Node *aux = this->head;
    this->head = node;
    this->head->next = aux;
  }
  this->size++;
};

int Stack::pop()
{
  Node *aux = this->head;
  int *value = this->head->getValue();
  std::cout << value << "hhello";
  this->head = this->head->next;
  this->size--;
  delete aux;
  return 1;
};
