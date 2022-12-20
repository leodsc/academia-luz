#include "node.hpp"

class Stack 
{
  private:
    int *size;
    Node *head;
  public:
    Stack();
    Node *top();
    int pop();
    void push(int value);
};
