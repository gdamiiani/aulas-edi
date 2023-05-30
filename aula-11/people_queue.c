#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int age;
  char gender;
} Person;

typedef struct {
  Person *people;
  int position;
  int size;
} Queue;

void initialize(Queue *queue, int size) {
  queue->people = malloc(size * sizeof(Person));
  queue->position = -1;
  queue->size = size;
}

void push(Queue *queue, Person person) {
  if (queue->position + 1 == queue->size) {
    return;
  }

  ++queue->position;

  queue->people[queue->position] = person;
}

Person pop(Queue *queue) {
  Person person;

  if (queue->position == -1) {
    return person;
  }

  person = queue->people[0];

  for (int i = 0; i < queue->position; ++i) {
    queue->people[i] = queue->people[i + 1];
  }

  --queue->position;

  return person;
}

void print_queue(Queue queue) {
  for (int i = 0; i <= queue.position; ++i) {
    printf("Nome: %s\t Idade: %d\t Gênero: %c\n", queue.people[i].name, queue.people[i].age, queue.people[i].gender);
  }
}

int main() {
  Queue queue;

  initialize(&queue, 5);

  Person p1;
  Person p2;

  strncpy(p1.name, "Jon", 4);
  p1.age = 32;
  p1.gender = 'M';

  strncpy(p2.name, "Mary", 5);
  p2.age = 19;
  p2.gender = 'F';

  push(&queue, p1);
  push(&queue, p2);

  print_queue(queue);

  pop(&queue);
  puts("");

  print_queue(queue);

  return 0;
}
