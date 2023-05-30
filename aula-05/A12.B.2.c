#include <stdio.h>

void copiarVetor(int vetor1[], int tamanho, int vetor2[]);

void imprimir(int vetor[], int quantidade) {

	int i;

	printf("\nOs numeros no vetor sao: ");

	for(i = 0; i < quantidade; i++) {

		printf("%d ", vetor[i]);

	}

}


int main() {

	int t = 5;

	int x[] = {1, 2, 3, 4, 5}, y[5];

	copiarVetor(x, t, y);

	imprimir(x, t);

	imprimir(y, t);

} 

void copiarVetor(int vetor1[], int tamanho, int vetor2[]) {
    for (int i = 0; i < tamanho; ++i) {
        vetor2[i] = vetor1[i];
    }
}
