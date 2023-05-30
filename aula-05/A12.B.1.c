#include <stdio.h>

void clearArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        array[i] = 0;
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6 };
    int arraySize = sizeof(array) / sizeof(int);

    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }

    puts("");

    clearArray(array, arraySize);

    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    
    puts("");

    return 0;
}
