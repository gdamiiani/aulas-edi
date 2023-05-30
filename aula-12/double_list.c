#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double *numbers;
  int index;
  int size;
} List;

void initialize(List *list, int size);

void insert(List *list, double number, int index);

double delete(List *list, int index);

void print_list(List list);

int main() {
  List list;

  initialize(&list, 4);
  
  insert(&list, 10.1, 0);
  insert(&list, 20.2, 1);
  insert(&list, 30.3, 2);
  insert(&list, 40.4, 1);

  print_list(list);

  delete(&list, 1);

  print_list(list);
}

void initialize(List *list, int size) {
  list->numbers = malloc(sizeof(double) * size);
  list->index = -1;
  list->size = size;
}

void insert(List *list, double number, int index) {
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

double delete(List *list, int index) {
  double out = list->numbers[index];

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
    printf("%.1lf ", list.numbers[i]);
  }

  puts("");
}
