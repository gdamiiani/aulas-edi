#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *numbers;
  int position;
  int size;
} Queue;

void initialize(Queue *queue, int size, void *type) {
  queue->numbers = malloc(size * sizeof(type));
  queue->position = -1;
  queue->size = size;
}

void enqueue(Queue *queue, int number) {
  if (queue->position + 1 == queue->size) {
    return;
  }

  ++queue->position;

//  *(queue->numbers + queue->position) = void (void *) number;
}

int main() {

  int x = 10;
  int y[] = {1,2,3};

  void *a;
  void *b = void 2;


  a = y;

  void *aux = a;

}
