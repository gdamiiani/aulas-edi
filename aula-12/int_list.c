#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *numbers;
  int index;
  int size;
} List;

void initialize(List *list, int size);

void insert(List *list, int number, int index);

int delete(List *list, int index);

void print_list(List list);

int smallest_number(List list);

int main() {
  List list;

  initialize(&list, 4);
  
  insert(&list, 10, 0);
  insert(&list, 20, 1);
  insert(&list, 30, 2);
  insert(&list, -40, 1);

  print_list(list);

  printf("Smallest number: %d\n", smallest_number(list));

  //delete(&list, 1);

  //print_list(list);
}

void initialize(List *list, int size) {
  list->numbers = malloc(sizeof(int) * size);
  list->index = -1;
  list->size = size;
}

void insert(List *list, int number, int index) {
  if (index < 0 || list->index + 1 == list->size) {
    return;
  }

  ++list->index;

  if (index >= list->index) {
    list->numbers[list->index] = number;
    return;
  }

  for (int i = list->index; i >= index; --i) {
    list->numbers[i + 1] = list->numbers[i];
  }

  list->numbers[index] = number;
}

int delete(List *list, int index) {
  int out = list->numbers[index];

  if (list->index == -1) {
    return out;
  }

  --list->index;

  for (int i = index; i <= list->index; ++i) {
    list->numbers[i] = list->numbers[i + 1];
  }

  return out;
}

void print_list(List list) {
  for (int i = 0; i <= list.index; ++i) {
    printf("%d ", list.numbers[i]);
  }

  puts("");
}

int smallest_number(List list) {
  if (list.index == -1) {
    return 0;
  }

  int out = list.numbers[0];

  for (int i = 0; i <= list.index; ++i) {
    if (list.numbers[i] < out) {
      out = list.numbers[i];
    }
  }

  return out;
}
