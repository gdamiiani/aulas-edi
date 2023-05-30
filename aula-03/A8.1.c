#include <stdio.h>

double mediaFinalAluno(double n1, double n2, double n3) {
    double media = (n2 + n3) / 2;

    if (n1 > n3 && n2 > n3) {
        media = (n1 + n2) / 2;
    } else if (n1 > n2 && n3 > n2) {
        media = (n1 + n3) / 2;
    }

    return media;
}

int main() {
    double n1;
    double n2;
    double n3;

    printf("digite a nota 1: ");
    scanf("%lf", &n1);

    printf("digite a nota 2: ");
    scanf("%lf", &n2);

    printf("digite a nota 3: ");
    scanf("%lf", &n3);

    double media = mediaFinalAluno(n1, n2, n3);

    printf("media: %.2lf\t", media);

    if (media >= 70) {
        puts("aprovado");
    } else if (media >= 40) {
        puts("exame final");
    } else {
        puts("reprovado");
    }

    return 0;
}
