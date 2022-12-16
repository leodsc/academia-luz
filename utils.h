#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0

#include "node.h"
#include "stack.h"
#include "linked_list.h"
#include "queue.h"
#include "tree.h"

// GENERAL

void showArray(int *array, int size) {
  printf("[ ");
  for (int i = 0; i < size-1; i++) {
    if (size-1 == 1) {
      printf("%d ", array[i]);
    } else if (i != size-1) {
      printf("%d, ", array[i]);
    }

    if (i % 10 == 0 && i != 0) {
      puts("");
    }
  }
  puts("]");
}

void showStack(Stack *stack) {
  Node *nextNode = NULL;
  printf("[ ");
  for (int i = 0; i < stack->size; i++) {
    if (nextNode == NULL) {
      nextNode = stack->head->next;
      printf("%d, ", stack->head->value);
    } else {
      if (i != stack->size-2) {
        printf("%d, ", nextNode->value);
      } else {
        printf("%d", nextNode->value);
      }
      nextNode = nextNode->next;
    }
  }
  puts(" ]");
}

void showQueue(Queue *queue) {
  Node *nextNode = NULL;
  printf("[ ");
  for (int i = 0; i < queue->size-1; i++) {
    if (nextNode == NULL) {
      nextNode = queue->head->next;
      printf("%d, ", queue->head->value);
    } else {
      if (i != queue->size-2) {
        printf("%d, ", nextNode->value);
      } else {
        printf("%d", nextNode->value);
      }
      nextNode = nextNode->next;
    }
  }
  puts(" ]");
}

#endif
