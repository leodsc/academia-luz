#include <iostream>

class Queue {
  private:
    LinkedList *linkedList = new LinkedList();
  public:
    Node *first() {
      return this->linkedList->getHead();
    }

    void enqueue(int value) {
      this->linkedList->insertEnd(value);
    }

    int dequeue() {
      return this->linkedList->removeFirst();
    }

    void print() {
      this->linkedList->print("Queue");
    }
};
