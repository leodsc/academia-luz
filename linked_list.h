#include <stdlib.h>
#include <stdio.h>

// LINKED LIST

typedef struct {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

LinkedList linkedList() {
  LinkedList l;
  l.head = malloc(sizeof(Node));
  l.tail = l.head;
  l.tail->next = NULL;
  l.size = 1;
  return l;
}

void addLinkedList(LinkedList *list, int value) {
  Node *aux = list->head;
  Node *item = malloc(sizeof(Node));
  item->value = value;

  if (list->size == 1) {
    list->head = item;
    list->tail = list->head;
  } else {
    list->tail->next = malloc(sizeof(Node));
    list->tail->next = item;
    list->tail = item;
    list->tail->next = NULL;
  }

  list->size++;
}

int getElementFromLinkedList(LinkedList *list, int value) {
  Node *currNode = list->head;
  int position = 0;

  while (currNode->value != value && currNode->next != NULL) {
    currNode = currNode->next;
    position++;
  }

  if (currNode->next == NULL && currNode->value != value) {
    return -1;
  }
  return position;
}

void addAtLinkedList(LinkedList *list, int value, int position) {
  Node *currNode = list->head;
  for (int i = 0; i < position; i++) {
    currNode = currNode->next;
  }
  if (currNode->next == NULL) {
    currNode->next = malloc(sizeof(Node));
    currNode->next->value = value;
  } else {
    Node *aux = currNode->next;
    free(currNode->next);
    currNode->next = malloc(sizeof(Node));
    currNode->next->value = value;
    currNode->next->next = aux;
  }
  list->size++;
}

Node *getHead(LinkedList *list) {
  return list->head;
}

Node *getTail(LinkedList *list) {
  return list->tail;
}

int removeFromPositionLinkedList(LinkedList *list, int position) {
  int value;
  Node *current = list->head;
  Node *aux;

  for (int i = 0; i < position-1; i++) {
    if (current->next == NULL) {
      return -1;
    }

    current = current->next;
  }

  if (current->next == NULL) {
    aux = list->head;
    value = list->head->value;
    free(aux);
    list->size--;
    return value;
  }

  aux = current->next;
  value = aux->value;
  current->next = aux->next;
  free(aux);
  list->size--;

  return value;
}

Node* getPosition(LinkedList *list, int position) {
  Node *currNode = list->head;
  for (int i = 0; i < list->size-1; i++) {
    if (i == position) {
      return currNode;
    }
    currNode = currNode->next;
  }
  return NULL;
}

void showLinkedList(LinkedList *list) {
  Node *currNode = list->head;
  for (int i = 0; i < list->size-1; i++) {
    if (currNode != NULL) {
      printf("%d ", currNode->value);
      currNode = currNode->next;
    }
  }
  
  if (list->size == 1) {
    puts("[]");
  } else {
    puts("]");
  }
}
