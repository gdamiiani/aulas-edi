#include <stdio.h>

#define LINES 3
#define COLUMNS 3

void func(int a[LINES][COLUMNS]) {
    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            a[i][j] = 0;
        }
    }
}

int main() {
    int n[LINES][COLUMNS];

    func(n);

    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            printf("%d ", n[i][j]);
        }

        puts("");
    }

    return 0;
}
