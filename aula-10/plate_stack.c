#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brand[50];
    char color[20];
    double weight;
} Plate;

typedef struct {
    int size;
    int position;
    Plate *plate;
} Stack;

void initialize(Stack *stack, int size);

void push(Stack *stack, Plate plate);

Plate pop(Stack *stack);

void print_stack(Stack stack);

int main() {
    Plate p1;
    Plate p2;
    Stack s;

    strncpy(p1.brand, "1st Added", 11);
    strncpy(p1.color, "Sky Blue", 9);
    p1.weight = 73.73;

    strncpy(p2.brand, "2nd Brand", 11);
    strncpy(p2.color, "Deep Purple", 9);
    p2.weight = 4.20;

    initialize(&s, 6);

    push(&s, p1);
    push(&s, p2);

    print_stack(s);

    return 0;
}

void initialize(Stack *stack, int size) {
    stack->size = size;
    stack->position = -1;
    stack->plate = malloc(sizeof(Plate) * stack->size);
}

void push(Stack *stack, Plate plate) {
    if (stack->position + 1 == stack->size) {
        return;
    }

    stack->position += 1;
    stack->plate[stack->position] = plate;
}

Plate pop(Stack *stack) {
    if (stack->position == -1) {
        return stack->plate[0];
    }

    stack->position -= 1;

    return stack->plate[stack->position + 1];
}

void print_stack(Stack stack) {
    for (int i = stack.position; i >= 0; --i) {
        printf("Marca:\t%s\n", stack.plate[i].brand);
        printf("Cor:\t%s\n", stack.plate[i].color);
        printf("Peso:\t%.2f kg\n", stack.plate[i].weight);
    }
}
