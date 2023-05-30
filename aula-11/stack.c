#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *numbers;
  int position;
  int size;
} Stack;

void initialize(Stack *stack, int size) {
  stack->numbers = malloc(size * sizeof(int));
  stack->position = -1;
  stack->size = size;
}

void push(Stack *stack, int number) {
  if (stack->position + 1 == stack->size) {
    return;
  }

  ++stack->position;

  stack->numbers[stack->position] = number;
}

int pop(Stack *stack) {
  if (stack->position == -1) {
    return 0;
  }

  --stack->position;

  return stack->numbers[stack->position + 1];
}

void print_stack_data(Stack stack) {
  for (int i = stack.position; i >= 0; --i) {
    printf("Stack[%d] = %d\n", i, stack.numbers[i]);
  }
}

int main() {
  Stack stack;

  initialize(&stack, 3);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, -20);

  print_stack_data(stack);

  pop(&stack);

  print_stack_data(stack);

  return 0;
}
