#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));
  int x = 10;
  char op;

  printf("reference (1) or value (2) ");
  scanf("%c", &op);

  switch (op) {
    case '1':
      p = &x;
      break;
    case '2':
      *p = x;
      break;
  }


  printf("p -> %p\n", p);
  printf("x -> %p\n\n", &x);

  printf("x = %d\n", x);
  printf("p = %d\n\n", *p);

  x = 20;

  printf("x = %d\n", x);
  printf("p = %d\n", *p);
}
