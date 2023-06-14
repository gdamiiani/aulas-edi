#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *rear;
  struct Node *front;
};

void initialize(struct Queue *queue) {
  queue->rear = queue->front = NULL;
}

void enqueue(struct Queue *queue, int data) {
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
    printf("%d ", queue.rear->data);
    queue.rear = queue.rear->next;
  }

  printf("\n");
}

int highest_number(struct Queue queue) {
  int highest = queue.rear->data;

  while (queue.rear) {
    if (highest < queue.rear->data) {
      highest = queue.rear->data;
    }

    queue.rear = queue.rear->next;
  }

  return highest;
}

int lowest_number(struct Queue queue) {
  int lowest = queue.rear->data;

  while (queue.rear) {
    if (lowest > queue.rear->data) {
      lowest = queue.rear->data;
    }

    queue.rear = queue.rear->next;
  }

  return lowest;
}

int main() {
  struct Queue queue;

  initialize(&queue);

  enqueue(&queue, 100);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  enqueue(&queue, 40);
  enqueue(&queue, 50);

  dequeue(&queue);
  dequeue(&queue);

  print_queue(queue);
  printf("maior %d\n", highest_number(queue));
  printf("menor %d\n", lowest_number(queue));
}
