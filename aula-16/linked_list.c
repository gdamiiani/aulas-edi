#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *front;
};

void initialize(struct LinkedList *linked_list) {
  linked_list->front = NULL;
}

void push(struct LinkedList *linked_list, int data) {
  struct Node *node = malloc(sizeof(struct Node));

  if (!node) {
    printf("List is full!\n");
    return;
  }

  node->data = data;
  node->next = linked_list->front;

  linked_list->front = node;
}

int pop(struct LinkedList *linked_list) {
  struct Node *node = linked_list->front;

  if (!node) {
    printf("List is empty!\n");
    return 0;
  }

  int data = node->data;

  linked_list->front = linked_list->front->next;

  free(node);

  return data;
}

void print_list(struct LinkedList linked_list) {
  if (!linked_list.front) {
    printf("List is empty!\n");
    return 0;
  }

  while (linked_list.front) {
    printf("%d ", linked_list.front->data);
    linked_list.front = linked_list.front->next;
  }

  printf("\n");
}

int main() {
  struct LinkedList linked_list;

  initialize(&linked_list);
  
  push(&linked_list, 10);
  push(&linked_list, 20);
  push(&linked_list, 30);
  push(&linked_list, 40);
  push(&linked_list, 50);

  pop(&linked_list);
  pop(&linked_list);
  pop(&linked_list);

  print_list(linked_list);
}
