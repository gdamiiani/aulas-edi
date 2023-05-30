#include <stdio.h>

#include "predio.h"

int mostrarMenu() {
    int op;
    
    do {
        puts("1) Inicializar prédio");
        puts("2) Alterar moradores");
        puts("3) Imprimir moradores uma unidade");
        puts("4) Imprimir moradores todas unidades");
        puts("5) Imprimir total moradores");
        puts("6) Imprimir moradores de cada andar");
        puts("7) Imprimir apartamentos vazios (sem moradores)");
        puts("8) Imprimir unidade com mais moradores");
        puts("9) Finalizar programa");

        scanf("%d", &op);
    } while (op < 1 || op > 9);
    
    return op;
}

void inicializarPredio(int predio[APTOS][ANDARES]) {
    for (int i = 0; i < APTOS; ++i) {
        for (int j = 0; j < ANDARES; ++j) {
            predio[i][j] = 0;
        }
    }
}


void alterarMoradoresUnidade(int predio[APTOS][ANDARES]) {
    int unidade;
    int andar;
    int moradores;
    
    printf("Número do andar (1-20): ");
    scanf("%d", &andar);
    
    printf("Número da unidade (1-8): ");
    scanf("%d", &unidade);
    
    printf("Número de moradores: ");
    scanf("%d", &moradores);
    
    predio[unidade - 1][andar - 1] = moradores;
}

void imprimirMoradoresUmaUnidade(int predio[APTOS][ANDARES]) {
    int unidade;
    
    printf("Número da unidade (1-8): ");
    scanf("%d", &unidade);
    
    printf("Andar   Unidade %d\n", unidade);
    
    for (int i = ANDARES - 1; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        printf("%d\n",  predio[unidade - 1][i]);
    }
}

void imprimirMoradoresTodasUnidades(int predio[APTOS][ANDARES]) {
    puts("Andar   Unidade 1   Unidade 2   Unidade 3   Unidade 4   Unidade 5   Unidade 6   Unidade 7   Unidade 8");
    
    for (int i = ANDARES - 1; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        for (int j = 0; j < APTOS; ++j) {
            printf("%d           ",  predio[j][i]);
        }
        
        puts("");
    }
}

void imprimirMoradoresPredio(int predio[APTOS][ANDARES]) {
    int total = 0;
    
    for (int i = 0; i < APTOS; ++i) {
        for (int j = 0; j < ANDARES; ++j) {
            total += predio[i][j];
        }
    }
    
    printf("O prédio possui %d moradores\n", total);
}

void imprimirMoradoresTodosAndares(int predio[APTOS][ANDARES]) {
    int total[20];
    
    for (int i = 0; i < ANDARES; ++i) {
        for (int j = 0; j < APTOS; ++j) {
            if (j == 0) {
                total[i] = predio[j][i];
            } else {
                total[i] += predio[j][i];
            }
        }
    }
    
    puts("Andar   Moradores");
    
    for (int i = ANDARES - 1; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        printf("%d\n", total[i]);
    }
}

void imprimirApartamentosVazios(int predio[APTOS][ANDARES]) {
    for (int i = 0; i < APTOS; ++i) {
        for (int j = 0; j < ANDARES; ++j) {
            if (predio[i][j] == 0) {
                printf("Apartamento %d/%d vazio (unidade/andar)\n", i + 1, j + 1);
            }
        }
    }
}

void unidadeMaiorMoradores(int predio[APTOS][ANDARES]) {
    int maior = 0;
    int unidade = 0;

    for (int i = 0; i < APTOS; ++i) {
        int aux = maior;
        maior = 0;
        
        for (int j = 0; j < ANDARES; ++j) {
            maior += predio[i][j];
        }
        
        if (maior > aux) {
            unidade = i;
        }
    }
    
    printf("A unidade com maior número de moradores é a %d\n", unidade + 1);
}
