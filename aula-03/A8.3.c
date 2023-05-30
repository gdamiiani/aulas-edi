#include <stdio.h>

void maiorEMenor(int n1, int n2, int n3, int n4, int n5) {
    int n[] = { n1, n2, n3, n4, n5 };
    int maior = n[0];
    int menor = n[0];

    for (int i = 0; i < 5; ++i) {
        if (maior < n[i]) {
            maior = n[i];
        } else if (menor > n[i]) {
            menor = n[i];
        }
    }

    printf("maior valor: %d\n", maior);
    printf("menor valor: %d\n", menor);
}

int main() {
    int n[5];

    printf("digite o numero 1: ");
    scanf("%d", &n[0]);

    printf("digite o numero 2: ");
    scanf("%d", &n[1]);

    printf("digite o numero 3: ");
    scanf("%d", &n[2]);

    printf("digite o numero 4: ");
    scanf("%d", &n[3]);

    printf("digite o numero 5: ");
    scanf("%d", &n[4]);

    maiorEMenor(n[0], n[1], n[2], n[3], n[4]);

    return 0;
}
