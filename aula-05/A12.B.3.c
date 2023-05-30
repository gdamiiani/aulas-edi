#include <stdio.h>
#include <string.h>

void copiarVetor(char vetor1[], char vetor2[], char vetorResultado[]);

int main() {

	char v1[] = "rosa", v2[] = "linda", v3 [50];

	copiarVetor(v1, v2, v3);

	printf("%s", v3);

}

void copiarVetor(char vetor1[], char vetor2[], char vetorResultado[]) {
    int i;

    for (i = 0; i < strlen(vetor1); ++i) {
        vetorResultado[i] = vetor1[i];
    }

    for (int j = 0; j < strlen(vetor2); ++j) {
        vetorResultado[i] = vetor2[j];
        ++i;
    }
}
