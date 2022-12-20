#include <iostream>

class LinkedList {
  private:
    Node *head;
    Node *tail;
    int size;
  
    void toggle(int pos, Node *previousNode, Node *currentNode) {
        // if erasing head
        if (pos == 0) {
          this->head = currentNode->getNext();
        } else {
          previousNode->setNext(currentNode->getNext());
        }
    }

    void deleteNode(Node *node) {
      delete node;
      this->size--;
    }

  public:
    LinkedList() {
      this->size = 0;
    }

    Node *getHead() {
      return this->head;
    }

    Node *getTail() {
      return this->tail;
    }

    void push(int value) {
      Node *node = new Node(value);
      if (this->size == 0) {
        this->head = node;
        this->tail = node;
      } else {
        Node *linkedNode = this->head;
        while (linkedNode->hasNext()) {
          linkedNode = linkedNode->getNext();
        }
        linkedNode->setNext(node);
      }
      this->size++;
    }

    int removeAt(int position) {

      if (this->size == 0) {
        return -1;
      }

      if (this->size == 1) {
        Node *aux = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        delete aux;
        this->size--;
      }

      // link previous deleted node to next one
      Node *lastNode;
      Node *node = this->head;
      for (int i = 0; i < this->size; i++) {
        if (i == position) {
          int value = node->getValue();

          this->toggle(i, lastNode, node);
          this->deleteNode(node);
          return value;
        }
        lastNode = node;
        node = node->getNext();
      }
      return -1;
    }

    int removeItem(int item) {
      Node *previousNode;
      Node *node = this->head;
      int i = 0;

      while (node->getValue() != item && node->hasNext()) {
        previousNode = node;
        node = node->getNext();
        i++;
      }

      if (!node->hasNext() && node->getValue() != item) {
        return -1;
      }

      int value = node->getValue();

      this->toggle(i, previousNode, node);
      this->deleteNode(node);

      return value;
    }

    void print() {
      if (this->size == 0) {
        cout << "The linked list is empty." << endl;
      } else {
        Node *node = this->head;
        for (int i = 0; i < this->size; i++) {
          cout << "(" << i << ") the value is " << node->getValue() << endl;
          node = node->getNext();
        }
      }
    }
};

