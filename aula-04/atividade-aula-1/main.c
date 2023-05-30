#include <stdio.h>

#include "predio.h"

int main()
{
    int predio[APTOS][ANDARES];
    int op;
    
    do {
        op = mostrarMenu();
    
        switch (op) {
           case 1:
                inicializarPredio(predio);
                puts("Prédio inicializado");
                break;
            case 2:
                alterarMoradoresUnidade(predio);
                break;
            case 3:
                imprimirMoradoresUmaUnidade(predio);
                break;
            case 4:
                imprimirMoradoresTodasUnidades(predio);
                break;
            case 5:
                imprimirMoradoresPredio(predio);
                break;
            case 6:
                imprimirMoradoresTodosAndares(predio);
                break;
            case 7:
                imprimirApartamentosVazios(predio);
                break;
            case 8:
                unidadeMaiorMoradores(predio);
                break;
            case 9:
                puts("Saindo do programa...");
        }
    } while (op != 9);

    return 0;
}
