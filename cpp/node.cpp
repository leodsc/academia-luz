#include <iostream>
using namespace std;

void log(string s) {
  cout << s << endl;
}

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

class BinaryTreeNode: Node {
  private:
    BinaryTreeNode *left;
    BinaryTreeNode *right;
  public:
    BinaryTreeNode(int v = 0) {value = v; left = nullptr; right = nullptr;}

    void print() {
      cout << "The value is: " << this->value << endl;
      if (this->left != nullptr) {
        cout << "The left child is: " << this->left->value << endl;
      }

      if (this->right != nullptr) {
        cout << "The right child is: " << this->right->value << endl;
      }

      if (this->right == nullptr && this->left == nullptr) {
        cout << "This node is a leaf." << endl;
      }
    }
};

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

void nodeMenu() {
  log("Adicionando três nós com valores 10, 50 e 60");
  Node *c1 = new Node(10);
  Node *c2 = new Node(50);
  Node *c3 = new Node(60);
  c1->print();

  log("Linkando primeiro nó (10) ao segundo (50)");
  *c1 + c2;
  log("Linkando segundo nó (50) ao terceiro (60)");
  *c2 + c3;
  c1->print();

  log("Removendo ligação do primeiro nó com o segundo");
  c1->remove();
  c1->print();

  log("Removendo ligação do primeiro nó com o último");
  c1->remove();
  c1->print();
}

void stackMenu() {
  int v;
  Stack *stack = new Stack();

  stack->print();

  log("Adicionando 4 nós com valores 500, 300, 400 e 200 à pilha");
  stack->push(500);
  stack->push(300);
  stack->push(400);
  stack->push(200);
  stack->print();

  log("removendo...");
  v = stack->pop();
  cout << "valor " << v << " removido" << endl;
  stack->print();

  log("removendo...");
  v = stack->pop();
  cout << "valor " << v << "removido" << endl;
  stack->print();

  log("Adicionando valor 900");
  stack->push(900);
  stack->print();
}

void queueMenu() {
  Queue *queue = new Queue();
  int v;

  queue->print();
  log("Adicionando 3 valores: 500, 100 e 200");
  queue->push(500);
  queue->push(100);
  queue->push(200);
  queue->print();

  v = queue->unshift();
  cout << "Removido primero valor: " << v << endl;
  queue->print();

  log("Adiconando valor 300");
  queue->push(300);
  queue->print();
}

void linkedListMenu() {
  LinkedList *linkedList = new LinkedList();
  linkedList->print();

  linkedList->push(100);
  linkedList->push(200);
  linkedList->push(300);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(1);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(0);
  linkedList->print();

  cout << "REMOVED..." << endl;
  linkedList->removeAt(0);
  linkedList->print();

  linkedList->push(500);
  cout << "ADDED..." << endl;
  linkedList->print();
}

void menu() {
  int choice;
  do {
    log("Escolha uma opção abaixo: ");
    log("1 - Nodes");
    log("2 - Stack");
    log("3 - Queue");
    log("4 - Linked List");
    log("0 - Sair");
    cin >> choice;

    switch (choice) {
      case 1: nodeMenu(); break;
      case 2: stackMenu(); break;
      case 3: queueMenu(); break;
      case 4: linkedListMenu(); break;
    }
  } while (choice != 0);
}

int main() {
  menu();
  return 0;
};
