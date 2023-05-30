#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[9];
    double distanciaPercorrida;
    double tempo;
    double velocidadeMedia;
} Carro;

void ler_carro(Carro *carro);

double calcular_velocidade(Carro carro);

void verificar_maior_velocidade(Carro carro1, Carro carro2);

int main() {
    Carro carros[2];

    for (int i = 0; i < 2; ++i) {
        ler_carro(&carros[i]);
        carros[i].velocidadeMedia = calcular_velocidade(carros[i]);
    }

    verificar_maior_velocidade(carros[0], carros[1]);

    return 0;
}

void ler_carro(Carro *carro) {
    printf("Placa do carro: ");
    fgets(carro->placa, 9, stdin);
    carro->placa[strcspn(carro->placa, "\n")] = 0;

    printf("Distância percorrida: ");
    scanf("%lf", &carro->distanciaPercorrida);

    printf("Tempo: ");
    scanf("%lf", &carro->tempo);
    while (getchar() != '\n');
}

double calcular_velocidade(Carro carro) {
    return carro.distanciaPercorrida / carro.tempo;
}

void verificar_maior_velocidade(Carro carro1, Carro carro2) {
    char placa[9];

    strncpy(placa, carro1.placa, 9);

    if (carro2.velocidadeMedia > carro1.velocidadeMedia) {
        strncpy(placa, carro2.placa, 9);
    } else if (carro1.velocidadeMedia == carro2.velocidadeMedia) {
        printf("A velocidade média dos carros %s e %s são iguais\n", carro1.placa, carro2.placa);
        return;
    }

    printf("A velocidade média do carro %s é a maior\n", placa);
}
