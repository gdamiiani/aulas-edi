#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int position;
    int *number;
} Stack;

void initialize(Stack *stack, int size);

void push(Stack *stack, int number);

int pop(Stack *stack);

void print_stack(Stack stack);

int main() {
    Stack s;
    initialize(&s, 6);

    push(&s, 100);
    push(&s, 30);
    push(&s, -10);
    push(&s, 20);
    push(&s, 20);
    push(&s, 20);
    push(&s, 120);

    print_stack(s);

    return 0;
}

void initialize(Stack *stack, int size) {
    stack->size = size;
    stack->position = -1;
    stack->number = malloc(sizeof(int) * stack->size);
}

void push(Stack *stack, int number) {
    if (stack->position + 1 == stack->size ||
            number >= stack->number[stack->position] && stack->position != -1) {
        return;
    }

    stack->position += 1;
    stack->number[stack->position] = number;
}

int pop(Stack *stack) {
    if (stack->position == -1) {
        return 0;
    }

    stack->position -= 1;

    return stack->number[stack->position + 1];
}

void print_stack(Stack stack) {
    for (int i = stack.position; i >= 0; --i) {
        printf("%d\n", stack.number[i]);
    }
}
