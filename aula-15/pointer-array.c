#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int) * 4);

  *p = 20;
  //*(p + 0) = 20;
  //p[0] = 20;
  *(p + 1) = 10;
  //p[1] = 10;

  printf("p -> %p\n", p);
  printf("p = %d\n", *p);
  printf("p = %d\n", *(p +1));

  free(p);
}
