#include <stdio.h>

double calcularAreaTriangulo(double base, double altura) {
    return (base * altura) / 2;
}

int main() {
    double base;
    double altura;

    printf("digite a base do triangulo: ");
    scanf("%lf", &base);

    printf("digite a altura do triangulo: ");
    scanf("%lf", &altura);

    double area = calcularAreaTriangulo(base, altura);

    printf("area: %.2lf\n", area);

    return 0;
}
