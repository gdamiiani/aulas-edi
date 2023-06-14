#include <stdio.h>
#include <stdlib.h>

struct Node {
  double data;
  struct Node *next;
};

struct Queue {
  struct Node *rear;
  struct Node *front;
};

void initialize(struct Queue *queue) {
  queue->rear = queue->front = NULL;
}

void enqueue(struct Queue *queue, double data) {
  struct Node *node = malloc(sizeof(struct Node));

  if (!node) {
    return;
  }

  node->data = data;
  node->next = NULL;

  if (!queue->rear || !queue->front) {
    queue->rear = queue->front = node;
    return;
  }

  queue->front = queue->front->next = node;
}

int dequeue(struct Queue *queue) {
  struct Node *node = queue->rear;

  if (!node) {
    return 0;
  }

  int data = node->data;

  queue->rear = queue->rear->next;

  free(node);

  return data;
}

void print_queue(struct Queue queue) {
  while (queue.rear) {
    printf("%.1lf ", queue.rear->data);
    queue.rear = queue.rear->next;
  }

  printf("\n");
}

int main() {
  struct Queue queue;

  initialize(&queue);

  enqueue(&queue, 10.1);
  enqueue(&queue, 20.2);
  enqueue(&queue, 30.3);
  enqueue(&queue, 40.4);
  enqueue(&queue, 50.5);

  dequeue(&queue);
  dequeue(&queue);

  print_queue(queue);
}
