// QUEUE

typedef struct {
  Node *head;
  Node *tail;
  int size;
} Queue;

Queue queue() {
  Queue q;

  q.head = malloc(sizeof(Node));
  q.size = 1;
  return q;
}

void enqueue(Queue *queue, int value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;

  if (queue->size == 1) {
    queue->head = node;
    queue->tail = queue->head;
  } else {
    queue->tail->next = malloc(sizeof(Node));
    queue->tail->next = node;
    queue->tail = node;
  }

  queue->size++;
}

int first(Queue *q) {
  if (q->size > 1) {
    return q->head->value;
  }
}

Node* dequeue(Queue *queue) {
  if (queue->size > 1) {
    Node *aux = queue->head;
    queue->head = queue->head->next;
    free(aux);
    queue->size--;
    return aux;
  } else {
    return NULL;
  }
}

