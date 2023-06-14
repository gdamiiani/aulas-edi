#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

void initialize(struct Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

void enqueue(struct Queue *queue, int data) {
  struct Node *node = malloc(sizeof(struct Node));

  if (!node) {
    printf("Queue is full!\n");
    return;
  }

  node->data = data;
  node->next = NULL;

  if (!queue->front || !queue->rear) {
    queue->front = node;
    queue->rear = node;
    return;
  }

  queue->front->next = node;
  queue->front = node;
}

int dequeue(struct Queue *queue) {
  struct Node *node = queue->rear;

  if (!node) {
    printf("Queue is empty!\n");
    return 0;
  }

  int data = node->data;

  queue->rear = queue->rear->next;

  free(node);

  return data;
}

void print_queue(struct Queue queue) {
  if (!queue.rear) {
    printf("Queue is empty!\n");
    return;
  }

  while (queue.rear) {
    printf("%d ", queue.rear->data);
    queue.rear = queue.rear->next;
  }

  printf("\n");
}

int main() {
  struct Queue queue;

  initialize(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  enqueue(&queue, 40);
  enqueue(&queue, 50);

  dequeue(&queue);
  dequeue(&queue);
  dequeue(&queue);

  print_queue(queue);
}
