#include <iostream>

class Queue {
  private:
    LinkedList *linkedList = new LinkedList();
  public:
    Node *first() {
      return this->linkedList->getHead();
    }

    void push(int value) {
      this->linkedList->enqueue(value);
    }

    int unshift() {
      return this->linkedList->dequeue();
    }

    void print() {
      this->linkedList->print("Queue");
    }
};
