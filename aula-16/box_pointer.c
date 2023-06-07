#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  double weight;
  char name[50];
} Box;

void print_box(Box box) {
  printf("id: %d\tweight: %.2lf\tname: %s\n", box.id, box.weight, box.name);
}

int main() {
  const int size = 2;
  Box *boxes = malloc(sizeof(Box) * size);
  Box box1;

  box1.id = 1;
  box1.weight = 200.0;
  strncpy(box1.name, "Bob", 3);

  boxes[0] = box1;

  boxes[1].id = 2;
  boxes[1].weight = 30.0;
  strncpy(boxes[1].name, "Michael", 7);

  for (int i = 0; i < size; ++i) {
    print_box(boxes[i]);
  }

  free(boxes);
}
