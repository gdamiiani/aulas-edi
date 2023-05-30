#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float *numbers;
  int position;
  int size;
} Queue;

void initialize(Queue *queue, int size) {
  queue->numbers = malloc(size * sizeof(float));
  queue->position = -1;
  queue->size = size;
}

void push(Queue *queue, float number) {
  if (queue->position + 1 == queue->size) {
    return;
  }

  ++queue->position;

  queue->numbers[queue->position] = number;
}

float pop(Queue *queue) {
  if (queue->position == -1) {
    return 0;
  }

  float out = queue->numbers[0];

  for (int i = 0; i < queue->position; ++i) {
    queue->numbers[i] = queue->numbers[i + 1];
  }

  --queue->position;

  return out;
}

void print_queue(Queue queue) {
  for (int i = queue.position; i >= 0; --i) {
    printf("Queue[%d] = %.2f\n", i, queue.numbers[i]);
  }
}

float main() {
  Queue queue;

  initialize(&queue, 3);

  push(&queue, 10.2);
  push(&queue, 20);
  push(&queue, -20);

  print_queue(queue);

  pop(&queue);

  print_queue(queue);

  return 0;
}
