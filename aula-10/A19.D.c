#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int position;
    int sum;
    int *number;
} Stack;

void initialize(Stack *stack, int size);

void push(Stack *stack, int number);

int pop(Stack *stack);

void print_stack(Stack stack);

int main() {
    Stack s;
    initialize(&s, 9);

    for (int i = 0; i < 9; ++i) {
        push(&s, 19);
    }

    print_stack(s);

    printf("SOMA: %d\n", s.sum);

    return 0;
}

void initialize(Stack *stack, int size) {
    stack->size = size;
    stack->position = -1;
    stack->sum = 0;
    stack->number = malloc(sizeof(int) * stack->size);
}

void push(Stack *stack, int number) {
    if (stack->position + 1 == stack->size ||
            stack->sum > 100) {
        puts("Stack cheia ou soma maior que 100");
        return;
    }

    stack->position += 1;
    stack->number[stack->position] = number;
    stack->sum += number;
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
