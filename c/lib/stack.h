#include <stdio.h>
#include <stdlib.h>

// STACK

typedef struct {
  Node *head;
  int size;
} Stack;

Stack* createStack() {
  Stack *s = malloc(sizeof(Stack));

  s->size = 0;
  return s;
};

void push(Stack *stack, int value) {
  Node *node = createNode(value);
  if (stack->size == 0) {
    stack->head = node;
  } else {
    Node *aux = stack->head;
    stack->head = node;
    stack->head->next = malloc(sizeof(Node));
    stack->head->next = aux;
  }

  stack->size++;
}

Node *top(Stack *stack) {
  printf("top: %d\n", stack->size);
  if (stack->size == 0) {
    return NULL;
  } else {
    return stack->head;
  }
}

int pop(Stack *stack) {
  if (stack->size > 0) {
    Node *aux = stack->head;
    stack->head = stack->head->next;
    stack->size -= 1;
    //free(head);
    printf("%d\n", stack->size);
    //return aux;
  }
  return 1;
}

