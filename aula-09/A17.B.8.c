#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char data[12];
    char nomeCliente[50];
    char texto[500];
} Reclamacao;

int main() {
    Reclamacao reclamacao[5];

    for (int i = 0; i < 5; ++i) {
        printf("Data da reclamação: ");
        fgets(reclamacao[i].data, 12, stdin);

        printf("Nome do(a) cliente: ");
        fgets(reclamacao[i].nomeCliente, 50, stdin);

        printf("Texto: ");
        fgets(reclamacao[i].texto, 500, stdin);

        reclamacao[i].numero = i;
        reclamacao[i].data[strcspn(reclamacao[i].data, "\n")] = 0;
        reclamacao[i].nomeCliente[strcspn(reclamacao[i].nomeCliente, "\n")] = 0;
        reclamacao[i].texto[strcspn(reclamacao[i].texto, "\n")] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        printf("A reclamação de número %d, aberta em %s, tem como solicitante o cliente %s se queixando de %s.\n", reclamacao[i].numero, reclamacao[i].data, reclamacao[i].nomeCliente, reclamacao[i].texto);
    }

    return 0;
}
