#ifndef PREDIO_H
#define PREDIO_H

#include <stdio.h>

#define APTOS 8
#define ANDARES 20

int mostrarMenu();

void inicializarPredio(int predio[APTOS][ANDARES]);

void alterarMoradoresUnidade(int predio[APTOS][ANDARES]);

void imprimirMoradoresUmaUnidade(int predio[APTOS][ANDARES]);

void imprimirMoradoresTodasUnidades(int predio[APTOS][ANDARES]);

void imprimirMoradoresPredio(int predio[APTOS][ANDARES]);

void imprimirMoradoresTodosAndares(int predio[APTOS][ANDARES]);

void imprimirApartamentosVazios(int predio[APTOS][ANDARES]);

void unidadeMaiorMoradores(int predio[APTOS][ANDARES]);
#endif
