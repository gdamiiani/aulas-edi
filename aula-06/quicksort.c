#include <stdio.h>

int partition(int n[], int low, int high) {
    int pivot = n[high];
    int pivot_index = low;

    for (int i = low; i < high; ++i) {
        if (n[i] <= pivot_index) {
            int aux = n[pivot_index];

            n[pivot_index] = n[i];
            n[i] = aux;

            ++pivot_index;
        }
    }

    int aux = n[pivot_index];

    n[pivot_index] = n[high];
    n[high] = aux;

    return pivot_index;
}

void quicksort(int n[], int low, int high) {
    if (low >= high || low < 0) {
        return;
    }

    int p = partition(n, low, high);

    quicksort(n, p + 1, high);
    quicksort(n, low, p - 1);
}

int main() {
    int n[] = {9, 2, 3, 7, 0, -2};

    quicksort(n, 0, 5);

    for (int i = 0; i < sizeof(n) / sizeof(n[0]); ++i) {
        printf("%d ", n[i]);
    }

    return 0;
}
