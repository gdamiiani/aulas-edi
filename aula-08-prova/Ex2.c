#include <stdio.h>

void validar_sequencia(int sequencia[], int tamanho) {
    if (tamanho < 10) {
        puts("Tamanho inválido.");
    }

    int somaTotal = 0;
    int somaQuatroPrimeiros = 0;
    int somaDoisUltimos = 0;
    int sexto = sequencia[5];
    int antepenultimo = sequencia[tamanho - 3];
    int maiorCincoPrimeiros;

    for (int i = 0; i < tamanho; ++i) {
        if (i == 0 || (maiorCincoPrimeiros < sequencia[i] && i < 5)) {
            maiorCincoPrimeiros = sequencia[i];
        }

        if (i < 4) {
            somaQuatroPrimeiros += sequencia[i];
        } else if (i > tamanho - 3) {
            somaDoisUltimos += sequencia[i];
        }

        somaTotal += sequencia[i];
    }

    if (somaTotal % 2 == 0) {
        puts("Regra 1 quebrada, sequência inválida!");
        return;
    }

    if (somaQuatroPrimeiros != somaDoisUltimos) {
        puts("Regra 2 quebrada, sequência inválida!");
        return;
    }

    if (maiorCincoPrimeiros - antepenultimo != sexto) {
        puts("Regra 2 quebrada, sequência inválida!");
        return;
    }

    puts("Sequência válida!");
}

int main() {
    int digitos[10];

    printf("Digite os digitos (separados por espaço): ");

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &digitos[i]);
    }

    validar_sequencia(digitos, 10);

    return 0;
}
