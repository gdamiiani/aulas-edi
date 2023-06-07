#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Box {
  int id;
  double weight;
};

struct Node {
  struct Box data;
  struct Node *next;
};

void push(struct Node **head_ref, struct Box new_data) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (!new_node) {
    printf("Linked list full!\n");
    return;
  }

  new_node->data = new_data;
  new_node->next = *head_ref;

  *head_ref = new_node;
}

struct Box pop(struct Node **head_ref) {
  struct Node *temp = *head_ref;
  struct Box data = temp->data;

  if (!*head_ref) {
    printf("Linked list empty!\n");
    return data;
  }

  *head_ref = (*head_ref)->next;

  free(temp);

  return data;
}

void print_node(struct Node *node) {
  while (node) {
    printf("[data] [id - %d  weight - %.2lf] -> [next] [%p]\n", node->data.id, node->data.weight, node->next);
    node = node->next;
  }
}

int main() {
  struct Node *node = NULL;
  struct Box box1;
  struct Box box2;

  box1.id = 1;
  box1.weight = 50;

  box2.id = 2;
  box2.weight = 100;

  push(&node, box1);
  push(&node, box2);

  print_node(node);
}
