#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

int show_menu(int rep, int amount) {
  int op;

  printf("-------------------------\n");
  printf("          Queue          \n");
  printf("-------------------------\n");
  printf("    1. Rep    %d\n", rep);
  printf("    2. Amount %d\n", amount);
  printf("    3. Run - INSERT\n");
  printf("    4. Run - DELETE\n");
  printf("    5. Run - PRINT\n");
  printf("    6. Clean screen\n");
  printf("-------------------------\n");

  return op;
}

int main() {
  int rep = 1000;
  int amount = 1;

  srand(time(NULL));

  while (1) {
    int op = show_menu(rep, amount);
    double average = 0;
    double clocks[amount];

    scanf("%d", &op);

    switch(op) {
      case 1:
        scanf("%d", &rep);
        break;
      case 2:
        scanf("%d", &amount);
        break;
      case 3:
        for (int i = 0; i < amount; ++i) {
          clocks[i] = stress_test_insert(rep);
          average += clocks[i];
          printf("Run %d - clocks elapsed: %lf\n", i + 1, clocks[i]);
        }

        average /= amount;

        printf("Average clocks elapsed: %lf\n", average);
        break;
      case 4:
        for (int i = 0; i < amount; ++i) {
          clocks[i] = stress_test_delete(rep);
          average += clocks[i];
          printf("Run %d - clocks elapsed: %lf\n", i + 1, clocks[i]);
        }

        average /= amount;

        printf("Average clocks elapsed: %lf\n", average);
        break;
      case 5:
        for (int i = 0; i < amount; ++i) {
          clocks[i] = stress_test_print(rep);
          average += clocks[i];
          printf("Run %d - clocks elapsed: %lf\n", i + 1, clocks[i]);
        }

        average /= amount;

        printf("Average clocks elapsed: %lf\n", average);
        break;
      case 6:
        system("clear");
        break;
    }

  }

  return 0;
}
