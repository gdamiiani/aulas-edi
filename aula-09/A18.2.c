#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Ponto;

Ponto ler_um_ponto();

double calcular_distancia_pontos(Ponto ponto1, Ponto ponto2);

int main() {
    Ponto pontos[2];

    pontos[0] = ler_um_ponto();
    pontos[1] = ler_um_ponto();
    
    double distancia = calcular_distancia_pontos(pontos[0], pontos[1]);

    printf("Distância entre os pontos: %.2lf\n", distancia);
}

Ponto ler_um_ponto() {
    Ponto ponto;

    printf("Eixo X: ");
    scanf("%lf", &ponto.x);

    printf("Eixo Y: ");
    scanf("%lf", &ponto.y);

    return ponto;
}

double calcular_distancia_pontos(Ponto ponto1, Ponto ponto2) {
    double distancia = sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));

    return distancia;
}
