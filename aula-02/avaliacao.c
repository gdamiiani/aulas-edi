#include <stdio.h>

int mostrarMenu();

void inicializarPredio(int predio[8][20]);

void alterarMoradoresUnidade(int predio[8][20]);

void imprimirMoradoresUmaUnidade(int predio[8][20]);

void imprimirMoradoresTodasUnidades(int predio[8][20]);

void imprimirMoradoresPredio(int predio[8][20]);

void imprimirMoradoresTodosAndares(int predio[8][20]);

void imprimirApartamentosVazios(int predio[8][20]);

void unidadeMaiorMoradores(int predio[8][20]);

int main()
{
    int predio[8][20];
    int op = 1;
    
    while (op > 0 && op < 9) {
        int op = mostrarMenu();
    
        switch (op) {
            case 1:
                inicializarPredio(&predio);
                puts("Prédio inicializado");
                break;
            case 2:
                alterarMoradoresUnidade(&predio);
                break;
            case 3:
                imprimirMoradoresUmaUnidade(&predio);
                break;
            case 4:
                imprimirMoradoresTodasUnidades(&predio);
                break;
            case 5:
                imprimirMoradoresPredio(&predio);
                break;
            case 6:
                imprimirMoradoresTodosAndares(&predio);
                break;
            case 7:
                imprimirApartamentosVazios(&predio);
                break;
            case 8:
                unidadeMaiorMoradores(&predio);
                break;
            case 9:
                return 0;
        }
    }

    return 0;
}

int mostrarMenu() {
    int op = 0;
    
    while (op < 1 || op > 9) {
        puts("1) Inicializar o prédio");
        puts("2) Alterar o número de moradores de uma unidade");
        puts("3) Consultar o número de moradores de uma unidade");
        puts("4) Imprimir o número de moradores de cada unidade");
        puts("5) Imprimir o número de moradores do prédio");
        puts("6) Imprimir o número total de moradores de cada andar");
        puts("7) Informar quais apartamentos estão vazios (ou seja, sem moradores)");
        puts("8) Identificar a unidade com o maior número de moradores");
        puts("9) Finalizar programa");
        scanf("%d", &op);
    }
    
    return op;
}

void inicializarPredio(int predio[8][20]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 20; ++j) {
            predio[i][j] = 0;
        }
    }
}


void alterarMoradoresUnidade(int predio[8][20]) {
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

void imprimirMoradoresUmaUnidade(int predio[8][20]) {
    int unidade;
    
    printf("Número da unidade (1-8): ");
    scanf("%d", &unidade);
    
    printf("Andar   Unidade %d\n", unidade);
    
    for (int i = 19; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        printf("%d\n",  predio[unidade - 1][i]);
    }
}

void imprimirMoradoresTodasUnidades(int predio[8][20]) {
    puts("Andar   Unidade 1   Unidade 2   Unidade 3   Unidade 4   Unidade 5   Unidade 6   Unidade 7   Unidade 8");
    
    for (int i = 19; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        for (int j = 0; j < 8; ++j) {
            printf("%d           ",  predio[j][i]);
        }
        
        puts("");
    }
}

void imprimirMoradoresPredio(int predio[8][20]) {
    int total = 0;
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 20; ++j) {
            total += predio[i][j];
        }
    }
    
    printf("O prédio possui %d moradores\n", total);
}

void imprimirMoradoresTodosAndares(int predio[8][20]) {
    int total[20];
    
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (j == 0) {
                total[i] = predio[j][i];
            } else {
                total[i] += predio[j][i];
            }
        }
    }
    
    puts("Andar   Moradores");
    
    for (int i = 19; i >= 0; --i) {
        if (i + 1 > 9) {
            printf("%d          ", i + 1);
        } else {
            printf("0%d          ", i + 1);
        }
        
        printf("%d\n", total[i]);
    }
}

void imprimirApartamentosVazios(int predio[8][20]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (predio[i][j] == 0) {
                printf("Apartamento %d/%d vazio (unidade/andar)\n", i + 1, j + 1);
            }
        }
    }
}

void unidadeMaiorMoradores(int predio[8][20]) {
    int maior = 0;
    int unidade = 0;

    for (int i = 0; i < 8; ++i) {
        int aux = maior;
        maior = 0;
        
        for (int j = 0; j < 20; ++j) {
            maior += predio[i][j];
        }
        
        if (maior > aux) {
            unidade = i;
        }
    }
    
    printf("A unidade com maior número de moradores é a %d\n", unidade + 1);
}