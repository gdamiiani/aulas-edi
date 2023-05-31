#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

typedef struct {
  char nome[51];
  char porto[4];
  int numero;
  float peso;
} Embarcacao;

void inserir(Embarcacao embarcacao);
void inicializar();
int verificarVazia();
int verificarCheia();
void imprimir();
Embarcacao remover();

typedef struct _fila {
	Embarcacao vetor[TAM_MAX];
	int final;
} Fila;

Fila f;

void inicializar(){
	f.final = -1;
}

int verificarVazia(){
	if(f.final == -1)
		return 1;
	else return 0;
}

int verificarCheia() {
	if(f.final == TAM_MAX - 1)
		return 1;
	else return 0;
}

void inserir(Embarcacao embarcacao){
	//verificar se a fila nao estah cheia
	if(!verificarCheia()) {
		//atualiza o final da fila	
		f.final++;
		//insere o numero no vetor no final
		f.vetor[f.final] = embarcacao;
	} else {
		//informa o usuario que a fila estah cheia
		printf("\nA fila estah cheia.");
	}
}

void imprimir(){
	//verificar se a fila nao estah vazia
	if(!verificarVazia()) {
		int i;
		printf("\nOs elementos na fila (embarcacao) sao: ");
		//percorrer o vetor de 0 ateh f.final
		for(i = 0; i <= f.final; i++) {
			//imprimir o elemento na posicao i
      Embarcacao elemento = f.vetor[i];

			printf("\nNome: %s\tPorto: %s\tNumero: %d\tPeso: %.2f kg", elemento.nome, elemento.porto, elemento.numero, elemento.peso);
    }
	} else {
		printf("\nA fila estah vazia.");
	}
}

Embarcacao remover() {
	//verificar se a fila não estah vazia
	if(!verificarVazia()) {
		Embarcacao aux;
		int i;
		//aux irá guardar o elemento do início da fila
		aux = f.vetor[0];
		//translada os elementos do inicio ao fim -1
		for(i = 0; i <= f.final -1; i++)
			//a posição i receber o valor da posição i+1
			f.vetor[i] = f.vetor[i+1];
		//atualizar o final da fila
		f.final--;
		return aux;
	} else {
		printf("A fila estah vazia.");
	}
}

int main(int argc, char *argv[]) {
  Embarcacao temp;

	int opcao;
	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o nome: ");
				scanf("%s", &temp.nome);
				printf("Digite o porto: ");
				scanf("%s", &temp.porto);
				printf("Digite o numero de inscricao: ");
				scanf("%d", &temp.numero);
				printf("Digite o peso total: ");
				scanf("%f", &temp.peso);
				inserir(temp);
				break;
			case 3:
				temp = remover();
				printf("\nEmbarcacao removida: ", temp);
			  printf("\n\tNome: %s\tPorto: %s\tNumero: %d\tPeso: %.2f", temp.nome, temp.porto, temp.numero, temp.peso);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 5);
}

