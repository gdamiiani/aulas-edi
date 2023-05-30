#include <stdio.h>
#include <string.h>

int consoantes(char palavra[]) {
    int out = 0;

    for (int i = 0; i < strlen(palavra); ++i) {
        char letra = palavra[i];

        if (letra == 'b' || letra == 'c' || letra == 'd' ||
                letra == 'f' || letra == 'g' || letra == 'h' ||
                letra == 'j' || letra == 'k' || letra == 'l' ||
                letra == 'm' || letra == 'n' || letra == 'p' ||
                letra == 'q' || letra == 'r' || letra == 's' ||
                letra == 't' || letra == 'v' || letra == 'w' ||
                letra == 'x' || letra == 'y' || letra == 'z') {
            ++out;
        }
    }

    return out;
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    printf("%d\n", consoantes(palavra));
}
