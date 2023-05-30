#include <stdio.h>

void maioresNumeros(int numeros[], int tamanho, int n) {
    for (int i = 0; i < tamanho; ++i) {
        if (numeros[i] > n) {
            printf("%d ", numeros[i]);
        }
    }

    puts("");
}

int main() {
    int numeros[100];
    int max;
    int n;

    scanf("%d", &max);

    for (int i = 0; i < max; ++i) {
        scanf("%d", &numeros[i]);
    }

    scanf("%d", &n);

    maioresNumeros(numeros, max, n);
}
