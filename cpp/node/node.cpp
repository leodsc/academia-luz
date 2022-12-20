#include <iostream>
#include "node.hpp"

Node::Node(int value)
{
  this->value = &value;
  this->next = NULL;
};

Node::~Node() {
  delete this->next;
}

int* Node::getValue() 
{
  return this->value;
};

void Node::setNext(Node *node) {
  this->next = node;
};

