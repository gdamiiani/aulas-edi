#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *numbers;
  int position;
  int size;
} Queue;

void initialize(Queue *queue, int size) {
  queue->numbers = malloc(size * sizeof(int));
  queue->position = -1;
  queue->size = size;
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
    printf("[%d] ", queue.numbers[i]);
  }

  puts("");
}

int first_even(Queue queue) {
  for (int i = 0; i <= queue.position; ++i) {
    if (queue.numbers[i] % 2 == 0) {
      return queue.numbers[i];
    }
  }

  return 0;
}

int main() {
  Queue queue;

  initialize(&queue, 3);

  enqueue(&queue, 3);
  enqueue(&queue, 4);
  enqueue(&queue, 5);

  print_queue(queue);

  printf("1º par: [%d]\n", first_even(queue));
  printf("peek:   [%d]\n", peek(queue));

  return 0;
}
