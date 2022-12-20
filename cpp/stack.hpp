#include <iostream>

class Stack {
  private:
    LinkedList *linkedList = new LinkedList();
  public:
    Node *top() {
      return this->linkedList->getHead();
    };

    void push(int value) {
      this->linkedList->push(value);
    };

    int pop() {
      return this->linkedList->pop();
    }

    void print() {
      this->linkedList->print("Stack");
    };
};
