#include <stdio.h>

void mostrar_molde(char molde[40][50], int comprimento, int largura) {
    int maxI = comprimento;
    int maxJ = largura;

    for (int i = 0; i < maxI; ++i) {
        if (i == 0) {
            for (int j = 0; j < maxJ; ++j) {
                printf("----");
            }

            puts("-");
        }

        for (int j = 0; j < maxJ; ++j) {
            printf("| %c ", molde[i][j]);
        }

        puts("|");

        if (i == maxI - 1) {
            for (int j = 0; j < maxJ; ++j) {
                printf("----");
            }

            puts("-");
        }
    }
}

void criar_molde(char molde[40][50], int comprimento, int largura, char estampa) {
    int maxI = comprimento;
    int maxJ = largura;

    for (int i = 0; i < maxI; ++i) {
        for (int j = 0; j < maxJ; ++j) {
            molde[i][j] = ((i + j) % 2 == 0) ? ' ' : estampa;
        }
    }

    mostrar_molde(molde, comprimento, largura);
}

void alterar_estampa(char molde[40][50], int comprimento, int largura) {
    int maxI = comprimento;
    int maxJ = largura;
    char estampa;

    for (int i = 0; i < maxI; ++i) {
        for (int j = 0; j < maxJ; ++j) {
                if (molde[i][j] != '' || molde[i][j] != ' ') {
                    estampa = molde[i][j];
                }

                char aux = molde[i][j];
                molde[i][j] = molde[i][j + 1];
                molde[i][j + 1] = aux;
        }
    }

    mostrar_molde(molde, comprimento, largura);
}

int main() {
    char molde[40][50];
    int comprimento;
    int largura;

    printf("Digite o comprimento do molde: ");
    scanf("%d", &comprimento);

    printf("Digite a largura do molde: ");
    scanf("%d", &largura);

    criar_molde(molde, comprimento, largura, '#');

    alterar_estampa(molde, comprimento, largura);

    return 0;
}
