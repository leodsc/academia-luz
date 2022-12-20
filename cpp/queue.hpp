#include <iostream>

class Queue {
  private:
    Node *head;
    Node *tail;
    int value;
    int size;
  public:
    Queue() {
      this->size = 0;
    }

    Node *first() {
      return this->head;
    }

    void push(int value) {
      Node *node = new Node(value);
      if (this->size == 0) {
        this->head = node;
        this->tail = node;
      } else {
        this->tail->setNext(node);
        this->tail = node;
      }
      this->size++;
    }

    int unshift() {
      if (this->size > 0) {
        Node *aux = this->head;
        int value = this->head->getValue();
        this->head = this->head->getNext();
        delete aux;
        this->size--;
        return value;
      }
      return -1;
    }

    void print() {
      if (this->size == 0) {
        cout << "Queue is empty." << endl;
      } else {
        Node *node = this->head;
        for (int i = 0; i < this->size; i++) {
          cout << "(" << i << ") value is " << node->getValue() << endl;
          node = node->getNext();
        }
      }
    }
};
