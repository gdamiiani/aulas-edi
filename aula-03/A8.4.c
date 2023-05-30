#include <stdio.h>

double mediaPonderada(double n1, double n2, double n3,
        double pesoN1, double pesoN2, double pesoN3) {
    return n1 * pesoN1 + n2 * pesoN2 + n3 * pesoN3;
}

int main() {
    double n[3];
    double peso[3];

    printf("digite a nota 1: ");
    scanf("%lf", &n[0]);

    printf("digite o peso da nota 1: ");
    scanf("%lf", &peso[0]);

    printf("digite a nota 2: ");
    scanf("%lf", &n[1]);

    printf("digite o peso da nota 2: ");
    scanf("%lf", &peso[1]);

    printf("digite a nota 3: ");
    scanf("%lf", &n[2]);

    printf("digite o peso da nota 3: ");
    scanf("%lf", &peso[2]);

    double media = mediaPonderada(n[0], n[1], n[2], peso[0], peso[1], peso[2]);

    printf("media: %.2lf\n", media);

    return 0;
}
