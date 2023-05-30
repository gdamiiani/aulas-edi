#include <stdio.h>
#include <string.h>

void imprimirConsoantes(char palavra[]) {
    for (int i = 0; i < strlen(palavra); ++i) {
        char letra = palavra[i];

        if (letra == 'b' || letra == 'c' || letra == 'd' ||
                letra == 'f' || letra == 'g' || letra == 'h' ||
                letra == 'j' || letra == 'k' || letra == 'l' ||
                letra == 'm' || letra == 'n' || letra == 'p' ||
                letra == 'q' || letra == 'r' || letra == 's' ||
                letra == 't' || letra == 'v' || letra == 'w' ||
                letra == 'x' || letra == 'y' || letra == 'z') {
            printf("%c ", letra);
        }
    }
    
    puts("");
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    imprimirConsoantes(palavra);
}
