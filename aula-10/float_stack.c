#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int position;
    float *number;
} Stack;

void initialize(Stack *stack, int size);

void push(Stack *stack, float number);

float pop(Stack *stack);

void print_stack(Stack stack);

int main() {
    Stack s;
    initialize(&s, 6);

    push(&s, 3.5);
    push(&s, 30);
    push(&s, -10);

    pop(&s);

    print_stack(s);

    return 0;
}

void initialize(Stack *stack, int size) {
    stack->size = size;
    stack->position = -1;
    stack->number = malloc(sizeof(float) * stack->size);
}

void push(Stack *stack, float number) {
    if (stack->position + 1 == stack->size) {
        return;
    }

    stack->position += 1;
    stack->number[stack->position] = number;
}

float pop(Stack *stack) {
    if (stack->position == -1) {
        return 0;
    }

    stack->position -= 1;

    return stack->number[stack->position + 1];
}

void print_stack(Stack stack) {
    for (int i = stack.position; i >= 0; --i) {
        printf("%.2f\n", stack.number[i]);
    }
}
