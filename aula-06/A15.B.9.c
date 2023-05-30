#include <stdio.h>

int quantidadeCaracteres(char string[]) {
    if (string[0] == '\0') {
        return -1;
    }

    return 1 + quantidadeCaracteres(string + 1);
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    printf("%d\n", quantidadeCaracteres(palavra));

    return 0;
}
