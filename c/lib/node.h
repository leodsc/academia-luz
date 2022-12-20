#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
  int value;
  int isEmpty;
  Node *next;
};

Node* createNode(int value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;
  return node;
}
