#include <stdio.h>

void funcaoSecreta(int c1[], int , int x);

void funcaoSecreta(int c1[], int i, int x) {
    int j = 0;
    int temp = 0;
    int valor;

    while (j < i) {
        scanf("%d", &valor);

        if (valor >= x) {
            temp = valor + temp;
            c1[j] = temp;
            j++;
        }
    }

    j = 0;

    while (j < i) {
        printf("%d ", c1[j]);
        ++j;
    }
}

int main() {

    return 0;
}
