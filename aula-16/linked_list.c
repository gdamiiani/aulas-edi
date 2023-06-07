#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node *next;
};

void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (!new_node) {
    printf("Linked list full!\n");
    return;
  }

  new_node->data = new_data;
  new_node->next = *head_ref;

  *head_ref = new_node;
}

int pop(struct Node **head_ref) {
  if (!*head_ref) {
    printf("Linked list empty!\n");
    return 0;
  }

  struct Node *temp = *head_ref;
  int data = temp->data;

  *head_ref = (*head_ref)->next;

  free(temp);

  return data;
}

void print_node(struct Node *node) {
  while (node) {
    printf("[data] [%d] -> [next] [%p]\n", node->data, node->next, node->next);
    node = node->next;
  }
}

int sum_all(struct Node *node) {
  int sum = 0;

  while (node) {
    sum += node->data;
    node = node->next;
  }

  return sum;
}

int main() {
  struct Node *node = NULL;

  push(&node, 1);
  push(&node, 2);
  push(&node, 3);
  push(&node, 4);

  pop(&node);

  print_node(node);

  printf("%d\n", sum_all(node));
}
