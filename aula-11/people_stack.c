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
} Stack;

void initialize(Stack *stack, int size) {
  stack->people = malloc(size * sizeof(Person));
  stack->position = -1;
  stack->size = size;
}

void push(Stack *stack, Person person) {
  if (stack->position + 1 == stack->size) {
    return;
  }

  ++stack->position;

  stack->people[stack->position] = person;
}

Person pop(Stack *stack) {
  if (stack->position == -1) {
    Person person;
    return person;
  }

  --stack->position;

  return stack->people[stack->position + 1];
}

void print_stack(Stack stack) {
  for (int i = stack.position; i >= 0; --i) {
    printf("Nome: %s\t Idade: %d\t Gênero: %c\n", stack.people[i].name, stack.people[i].age, stack.people[i].gender);
  }
}

int main() {
  Stack stack;

  initialize(&stack, 5);

  Person p1;
  Person p2;

  strncpy(p1.name, "Jon", 4);
  p1.age = 32;
  p1.gender = 'M';

  strncpy(p2.name, "Mary", 5);
  p2.age = 19;
  p2.gender = 'F';

  push(&stack, p1);
  push(&stack, p2);

  print_stack(stack);

  pop(&stack);
  puts("");

  print_stack(stack);

  return 0;
}
