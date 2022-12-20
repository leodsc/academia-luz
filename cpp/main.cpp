#include <iostream>
#include "stack.hpp"
using namespace std;

int main() {
  Stack *stack = new Stack();
  stack->push(3);
  stack->push(5);
  stack->push(4);

  cout << stack->top()->getValue() << endl;
  int v = stack->pop();
  cout << v;
  //cout << stack->top()->getValue();

  return 0;
};
