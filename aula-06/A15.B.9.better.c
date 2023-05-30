#include <stdio.h>

int quantidadeCaracteres(char string[]) {
    int func(char string[], int index) {
        if (string[index] != '\0') {
            return func(string, ++index);
        }

        return index - 1;
    }

    return func(string, 0);
}

int main() {
    char palavra[100];

    fgets(palavra, 100, stdin);

    printf("%d\n", quantidadeCaracteres(palavra));

    return 0;
}
