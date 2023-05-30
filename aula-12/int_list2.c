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

int show_menu();

int smallest_number(List list);

int main() {
  List list;

  initialize(&list, 1);

  while (1) {
    int op = show_menu();
    int number;
    int index;
    int size;

    switch (op) {
      case 0:
        printf("Type the list size: ");
        scanf("%d", &size);

        initialize(&list, size);
        break;
      case 1:
        printf("Type a number: ");
        scanf("%d", &number);

        printf("Type an index: ");
        scanf("%d", &index);

        insert(&list, number, index);
        break;
      case 2:
        printf("Type an index: ");
        scanf("%d", &index);

        delete(&list, index);
        break;
      case 3:
        print_list(list);
        break;
      case 4:
        printf("Smallest number: %d\n", smallest_number(list));
        break;
      case 9:
        printf("Exiting...\n");
        return 0;
    }
  }
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

int show_menu() {
  int op;
  puts("--------------------------");
  puts("---        List        ---");
  puts("--------------------------");
  puts("--- 0. Initialize      ---");
  puts("--- 1. Insert          ---");
  puts("--- 2. Delete          ---");
  puts("--- 3. Print           ---"); 
  puts("--- 4. Smallest number ---");
  puts("--- 9. Exit            ---");
  puts("--------------------------");
  scanf("%d", &op);
  return op;
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
