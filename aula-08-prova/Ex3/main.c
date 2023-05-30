#include <stdio.h>
#include "gPredio.h"

int main()
{
    int opcao = 0;
    int andar, unidade, numero;
    int uniMaior, andarMaior, nMoradores;
    int total = 0;

    do {
        //retorno da flecha
        printf("\n0) Mais moradores (funcionalidade nova)");
        printf("\n1) Inicializar o predio");
        printf("\n2) Alterar o numero de moradores de uma unidade");
        printf("\n3) Consultar o numero de moradores de uma unidade");
        printf("\n4) Imprimir o numero de moradores de cada unidade");
        printf("\n5) Imprimir o numero de moradores do predio");
        printf("\n6) Imprimir o numero total de moradores de cada andar");
        printf("\n7) Informar quais apartamentos estao vazios (ou seja, sem moradores)");
        printf("\n8) Identificar a unidade com o maior numero de moradores");
        printf("\n9) Finalizar programa.");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0:
                maisMoradores();
                break;
            case 1:
                inicializarPredio();
                break;
            case 2: 
                printf("Digite o andar: ");
                scanf("%d", &andar);
                printf("Digite a unidade: ");
                scanf("%d", &unidade);
                printf("Digite o numero de moradores: ");
                scanf("%d", &numero);
                informarMoradores(andar, unidade, numero);
                break;
            case 3:
                printf("Digite o andar: ");
                scanf("%d", &andar);
                printf("Digite a unidade: ");
                scanf("%d", &unidade);
                exibirMoradores(andar, unidade);
                break;
            case 4:
                imprimirPredio();
                break;
            case 5:
                total = calcularTotalMoradores();
                printf("\nTotal de moradores: %d", total);
                break;
            case 6:
                calcularTotalMoradoresAndares();
                break;
            case 7:
                imprimirApartamentosVazios();
                break;
            case 8:
                informarUnidadeMaiorMoradores();
                break;
            case 9:
                printf("Saindo do programa...");
                break;
            default:
            printf("\nDigite um numero valido (0 a 9).");
        }
    } while (opcao != 9);
    
    return 0;
}
