#include <stdio.h>
#include "gPredio.h"

#define ANDARES 20
#define APTOS 8

int predio[ANDARES][APTOS];

// Funcionalidade nova
void maisMoradores() {
    printf("Apartamentos: ");

    for (int i = 0; i < ANDARES - 1; ++i) {
        for (int j = 0; j < APTOS; ++j) {
            if (predio[i][j] > predio[i + 1][j]) {
                printf("%d %d\t", i + 1, j + 1);
            }
        }
    }
}

void inicializarPredio() {
	int i, j;
    for(i = 0; i < ANDARES; i++) {
        for(j = 0; j < APTOS; j++) {
            predio[i][j] = 0;
        }
    }
}

void informarMoradores(int andar, int unidade, int numero) {
    predio[andar-1][unidade-1] = numero;
}


void exibirMoradores(int andar, int unidade) {
    printf("O numero de moradores do apartamento %d %d eh: %d", andar, unidade,
        predio[andar-1][unidade-1]);
}

void imprimirPredio() {
	int i, j;
    printf("Andar");
    for(i = 0; i < APTOS; i++)
        printf("\tUnd %d", i+1);
    printf("\n");
    for(i = ANDARES-1; i >= 0; i--) {
            printf("%d\t", i+1);
            for(j = 0; j < APTOS; j++) {
                printf("%d\t", predio[i][j]);    
    		}
        printf("\n");
    }    
}

int calcularTotalMoradores() {
    int total = 0, i, j;
    for(i = 0; i < ANDARES; i++) {
        for(j = 0; j < APTOS; j++) {
            total += predio[i][j];
        }
    }
    return total;
}

void calcularTotalMoradoresAndares(){
	int i, j;
    for(i = 0; i < ANDARES; i++) {
        int total = 0;
        for(j = 0; j < APTOS; j++) {
            total += predio[i][j];
        }
        printf("\nTotal de moradores do andar %d: %d",i+1, total);
    }    
}

void imprimirApartamentosVazios() {
	int i, j;
    for(i = 0; i < ANDARES; i++) {
        for(j = 0; j < APTOS; j++) {
            if(predio[i][j] == 0)
                printf("\nAndar %d Unidade %d esta vazia\t", i+1, j+1);    
        }
    }    
}

void informarUnidadeMaiorMoradores() {
    int uniMaior = 0, i, j, andarMaior = 0;
    int nMoradores = predio[0][0];
    for(i =0; i < ANDARES; i++) {
        for(j = 0; j < APTOS; j++) {
            if(nMoradores < predio[i][j]) {
                uniMaior = j;
                andarMaior = i;
                nMoradores = predio[i][j];
            }
        }
    }
    printf("O andar %d unidade %d tem o maior numero de moradores %d", 
        andarMaior+1, uniMaior+1, nMoradores);
}
    
