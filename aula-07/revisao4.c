#include <stdio.h>

double calcularArea(double base_maior, double base_menor, double altura) {
    return (base_maior + base_menor) * altura / 2;
}

void verificarMaiorArea(double area1, double area2) {
    double maior_area = (area1 > area2) ? area1 : area2;

    printf("Maior área: %.2lf\n", maior_area);
}

int main() {
    double base_maior[2];
    double base_menor[2];
    double altura[2];
    double area[2];

    for (int i = 0; i < 2; ++i) {
        printf("Digite a base maior do trapézio %d: ", i + 1);
        scanf("%lf", &base_maior[i]);

        printf("Digite a base menor do trapézio %d: ", i + 1);
        scanf("%lf", &base_menor[i]);

        printf("Digite a altura do trapézio %d: ", i + 1);
        scanf("%lf", &altura[i]);

        area[i] = calcularArea(base_maior[i], base_menor[i], altura[i]);

        printf("Área trapézio %d: %.2lf\n", i + 1, area[i]);
    }

    verificarMaiorArea(area[0], area[1]);
}
