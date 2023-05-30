#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    int numero;
    char data[12];
    char nomeSolicitante[50];
    char nomeAdvogado[50];
} typedef Processo;

int main() {
    Processo processo;

    printf("Data do processo: ");
    fgets(processo.data, 12, stdin);

    printf("Nome do solicitante: ");
    fgets(processo.nomeSolicitante, 50, stdin);

    printf("Nome do advogado: ");
    fgets(processo.nomeAdvogado, 50, stdin);

    printf("Número do processo: ");
    scanf("%d", &processo.numero);

    processo.data[strcspn(processo.data, "\n")] = 0;
    processo.nomeSolicitante[strcspn(processo.nomeSolicitante, "\n")] = 0;
    processo.nomeAdvogado[strcspn(processo.nomeAdvogado, "\n")] = 0;

    printf("O processo de número %d, aberto em %s, tem como solicitante %s representado por %s.\n", processo.numero, processo.data, processo.nomeSolicitante, processo.nomeAdvogado);

    return 0;
}
