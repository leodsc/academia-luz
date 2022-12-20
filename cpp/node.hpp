#include <iostream>
using namespace std;

class Node {
  private:
    Node *next;
  protected:
    int value;
  public:
    Node(int v = 0) {value = v; next = nullptr;}
             
    void operator + (Node *node) {
      if (this->next == nullptr) {
        this->next = node;
      }
    }

    bool hasNext() {
      return this->next != nullptr;
    }

    Node *getNext() {
      return this->next;
    }

    void setNext(Node *next) {
      this->next = next;
    } 

    int getValue() {
      return this->value;
    }
    
    void remove() {
      Node *aux = this->next;
      if (this->next->hasNext()) {
        this->next = this->next->getNext();
      } else {
        this->next = nullptr;
      }
      delete aux;
    }

    void print() {
      cout << "The value is: " << this->value << endl;
      if (this->next != nullptr) {
        cout << "The next value is: " << this->next->value << endl;
      } else {
        cout << "No next value" << endl;
      }
    }
};

