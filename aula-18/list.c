#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct List {
  int size;
  struct Node *head;
  struct Node *tail;
};

void initialize(struct List *list) {
  list->size = -1;
  list->head = list->tail = NULL;
}

void add(struct List *list, int data, int index) {
  struct Node *node = malloc(sizeof(struct Node));

  if (!node) {
    printf("List is full!\n");
    return;
  }

  node->data = data;
  node->next = NULL;
  ++list->size;

  if (list->head == NULL && list->tail == NULL) {
    list->head = list->tail = node;
    return;
  }

  if (index <= 0) {
    node->next = list->tail;
    list->tail = node;
    return;
  }

  if (index >= list->size) {
    list->head = list->head->next = node;
    return;
  }

  struct Node *node_before = list->tail;

  while (index > 1) {
    node_before = node_before->next;
    --index;
  }

  struct Node *node_after = node_before->next;

  node_before->next = node;
  node->next = node_after;
}

int delete(struct List *list, int index) {
  if (index < 0 || index > list->size) {
    printf("Invalid index!\n");
    return 0;
  }

  --list->size;

  if (index == 0) {
    struct Node *node = list->tail;
    int data = node->data;

    list->tail = node->next;
    free(node);

    return data;
  }

  struct Node *node_before = list->tail;

  while (index > 1) {
    node_before = node_before->next;
    --index;
  }

  struct Node *node = node_before->next;
  int data = node->data;

  if (node == list->head) {
    list->head = node_before;
  }

  struct Node *node_after = node->next;

  node_before->next = node_after;
  free(node);

  return data;
}

void print_list(struct List list) {
  while (list.tail) {
    printf("[%d] ", list.tail->data);
    list.tail = list.tail->next;
  }

  printf("\n");
}

int main() {
  struct List list;

  initialize(&list);

  add(&list, 10, 0);
  add(&list, 20, 1);
  add(&list, 30, 2);
  add(&list, 40, 1);

  delete(&list, 2);
  delete(&list, 2);

  print_list(list);
}
