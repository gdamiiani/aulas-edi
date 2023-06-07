#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "random_int.h"

void initialize(Queue *queue, int size) {
  queue->position = -1;
  queue->size = SIZE;
}

void enqueue(Queue *queue, int number) {
  if (queue->position + 1 == queue->size) {
    return;
  }

  ++queue->position;

  queue->numbers[queue->position] = number;
}

int dequeue(Queue *queue) {
  if (queue->position == -1) {
    return 0;
  }

  int out = queue->numbers[0];

  for (int i = 0; i < queue->position; ++i) {
    queue->numbers[i] = queue->numbers[i + 1];
  }

  --queue->position;

  return out;
}

int peek(Queue queue) {
  if (queue.position == -1) {
    return 0;
  }

  return queue.numbers[queue.position];
}

void print_queue(Queue queue) {
  for (int i = 0; i <= queue.position; ++i) {
    //printf("[%d] ", queue.numbers[i]);
  }

  puts("");
}

Queue create_and_fill_queue(int size) {
  Queue queue;

  initialize(&queue, size);

  for (int i = 0; i < size; ++i) {
    enqueue(&queue, random_int());
  }

  return queue;
}

void free_queue(Queue *queue) {
  for (int i = 0; i <= queue->position; ++i) {
    dequeue(queue);
  }
}

double stress_test_insert(int size) {
  double start;
  double elapsed;
  Queue queue;

  start = clock();
  queue = create_and_fill_queue(size);
  elapsed = clock() - start;

  return elapsed;
}

double stress_test_delete(int size) {
  double start;
  double elapsed;
  Queue queue = create_and_fill_queue(size);

  start = clock();
  free_queue(&queue);
  elapsed = clock() - start;

  return elapsed;
}

double stress_test_print(int size) {
  double start;
  double elapsed;
  Queue queue = create_and_fill_queue(size);
  
  start = clock();
  print_queue(queue);
  elapsed = clock() - start;

  return elapsed;
}
