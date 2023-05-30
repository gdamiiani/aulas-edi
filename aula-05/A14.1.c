#include <stdio.h>
#include <string.h>

void contarPontuacao(char palavra[]) {
    for (int i = 0; i < strlen(palavra); ++i) {
        char letra = palavra[i];

        if (letra == '.' || letra == ';' || letra == ',' ||
                letra == '!' || letra == '?') {
            printf("%c ", letra);
        }
    }

    puts("");
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    contarPontuacao(palavra);
}
