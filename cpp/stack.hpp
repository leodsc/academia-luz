#include <iostream>

class Stack {
  private:
    int value;
    int size;
    Node *head;
  public:
    Stack() {
      this->size = 0;
    };

    Node *top() {
      return this->head;
    };

    void push(int value) {
      Node *node = new Node(value);
      if (this->size == 0) {
        this->head = node;
      } else {
        Node *aux = this->head;
        this->head = node;
        this->head->setNext(aux);
      }
      this->size++;
    };

    int pop() {
      if (this->head != nullptr) {
        Node *aux = this->head;
        int value = this->head->getValue();
        this->head = aux->getNext();
        this->size--;
        delete aux;
        return value;
      }
      return -1;
    }

    void print() {
      if (this->size > 0) {
        Node *node = this->head;
        cout << "[ ";
        for (int i = 0; i < this->size; i++) {
          if (i != this->size-1) {
            cout << node->getValue() << ", ";
          } else {
            cout << node->getValue();
          }
          node = node->getNext();
        }
        cout << " ]" << endl;
      } else {
        cout << "Stack is empty" << endl;
      }
    };
};
