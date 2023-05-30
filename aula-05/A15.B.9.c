#include <stdio.h>

int quantidadeCaracteres(char string[], int quantidade) {
    if (string[quantidade] != '\0') {
        ++quantidade;
        return quantidadeCaracteres(string, quantidade);
    }

    return quantidade - 1;
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    printf("%d\n", quantidadeCaracteres(palavra, 0));

    return 0;
}
