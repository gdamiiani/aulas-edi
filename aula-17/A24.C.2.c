#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  char id[10];
  int class;
};

struct Node {
  struct Student data;
  struct Node *next;
};

struct Queue {
  struct Node *rear;
  struct Node *front;
};

void initialize(struct Queue *queue) {
  queue->rear = queue->front = NULL;
}

void enqueue(struct Queue *queue, struct Student data) {
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

struct Student dequeue(struct Queue *queue) {
  struct Node *node = queue->rear;
  struct Student data = node->data;

  if (!node) {
    return data;
  }


  queue->rear = queue->rear->next;

  free(node);

  return data;
}

void print_queue(struct Queue queue) {
  while (queue.rear) {
    struct Student data = queue.rear->data;
    printf("nome %s\tturma %d\tprontuario %s\n", data.name, data.class, data.id);
    queue.rear = queue.rear->next;
  }

  printf("\n");
}

int main() {
  struct Queue queue;
  struct Student student[2];
  
  strncpy(student[0].name, "John", 4);
  strncpy(student[0].id, "HT11122233", 10);
  student[0].class = 1;
  
  strncpy(student[1].name, "Wilson", 6);
  strncpy(student[1].id, "HT55544433", 10);
  student[1].class = 1;

  initialize(&queue);

  enqueue(&queue, student[0]);
  enqueue(&queue, student[1]);

  print_queue(queue);

  dequeue(&queue);

  print_queue(queue);
}
