#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "random_int.h"

void initialize(struct Queue *queue) {
  queue->head = queue->tail = NULL;
}

void enqueue(struct Queue *queue, int data) {
  struct Node *node = malloc(sizeof(struct Node));

  if (!node) {
    printf("Queue is full!\n");
    return;
  }

  node->data = data;
  node->next = NULL;

  if (!queue->head || !queue->tail) {
    queue->head = queue->tail = node;
    return;
  }

  queue->head = queue->head->next = node;
}

int dequeue(struct Queue *queue) {
  struct Node *node = queue->tail;
  int data = node->data;

  if (!node) {
    printf("Queue is empty!");
    return 0;
  }

  queue->tail = queue->tail->next;

  free(node);

  return data;
}

int peek(struct Queue queue) {
  if (!queue.tail) {
    printf("Queue is empty!");
    return 0;
  }

  return queue.tail->data;
}

void print_queue(struct Queue queue) {
  while (queue.tail) {
    //printf("[%d] ", queue.tail->data);
    queue.tail = queue.tail->next;
  }

  puts("");
}

struct Queue create_and_fill_queue(int size) {
  struct Queue queue;

  initialize(&queue);

  for (int i = 0; i < size; ++i) {
    enqueue(&queue, random_int());
  }

  return queue;
}

void free_queue(struct Queue *queue) {
  while(queue->tail) {
    dequeue(queue);
  }
}

double stress_test_insert(int size) {
  double start;
  double elapsed;
  struct Queue queue;

  start = clock();
  queue = create_and_fill_queue(size);
  elapsed = clock() - start;

  return elapsed;
}

double stress_test_delete(int size) {
  double start;
  double elapsed;
  struct Queue queue = create_and_fill_queue(size);

  start = clock();
  free_queue(&queue);
  elapsed = clock() - start;

  return elapsed;
}

double stress_test_print(int size) {
  double start;
  double elapsed;
  struct Queue queue = create_and_fill_queue(size);
  
  start = clock();
  print_queue(queue);
  elapsed = clock() - start;

  return elapsed;
}
