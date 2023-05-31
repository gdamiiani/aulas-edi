#include <stdio.h>
#define TAM_MAX 10

typedef struct _lista {
	int vetor[TAM_MAX];
	int final;
} Lista;

Lista l;

void inserir(int numero, int posicao);
void imprimir();
int remover(int posicao);
void inicializar();
int verificarVazia();
int verificarCheia();

void removerMaiorQue(int valor);

void inicializar(){
	l.final = -1;	
}

int verificarVazia(){
	if(l.final == -1)
		return 1;
	else return 0;
}

int verificarCheia(){
	if(l.final == TAM_MAX - 1)
		return 1;
	else return 0;
}

void inserir(int numero, int posicao){
	//verificar se a lista nao estah cheia
	if(!verificarCheia()) {
		//verifica se a posicao eh maior ao final
		if(posicao > l.final) {
			//atualiza final
			l.final++;
			//guarda elemento na posicao final
			l.vetor[l.final] = numero;
		} else {
			int i;
			//deixar a posicao livre translando os elementos
			for(i = l.final; i >= posicao; i--)
				l.vetor[i+1] = l.vetor[i];
			//guarda elemento na posicao desejada
		    l.vetor[posicao] = numero;
			//atualiza final
			l.final++;
		}
	} else {
		//se ela estiver cheia, avisar usuario
		printf("\nA lista estah cheia.");
	}
}

void imprimir() {
	//verificar se a lista não está vazia
	if(!verificarVazia()) {
		//define uma variável auxiliar
		int i;
		printf("\nOs numeros na lista sao: ");
		//percorrer o vetor do inicio ateh final
		for(i = 0; i <= l.final; i++)
			//imprimir o elemento na posicao i
			printf("%d ", l.vetor[i]);
	} else {
		//se estiver vazia, informa o usuario
		printf("\nA lista esta vazia");
	}
}

int remover(int posicao) {
	//verifica se a lista nao estah vazia
	if(!verificarVazia()) {
		//verifica se existe elemento valido na posicao desejada
		if(posicao <= l.final) {
			int i;
			//define uma variavel auxiliar
			int aux = 0;
			//variavel auxiliar guarda o elemento da posicao
			aux = l.vetor[posicao];
			//transladar os elementos da posicao ate final - 1
			for(i = posicao; i < l.final; i++)
				l.vetor[i] = l.vetor[i+1];
			//atualiza o final da lista
			l.final--;
			//retorna elemento removido
			return aux;
		} else {
			//se nao existe elemento na posicao, informa o usuario
			printf("\nNao existe elemento na posicao indicada.");
		}
	} else {
		//se lista vazia, informa o usuario
		printf("\nA lista estah vazia.");
	}
	return 0;
}

void removerMaiorQue(int valor) {
  if (verificarVazia()) {
		printf("\nA lista estah vazia.");
    return;
  }

  for (int i = 0; i <= l.final; ++i) {
    if (l.vetor[i] > valor) {
      if (i == l.final) {
        l.vetor[i] = 0;
      }
      for (int j = i; j < l.final; ++j) {
        l.vetor[j] = l.vetor[j + 1];
      }

      --l.final;
    }
  }
}

int main(int argc, char *argv[]) {
	int opcao, temp, posicao;
	
	do {
		//exibir o menu
		printf("\n MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Exibir");
		printf("\n5. Remover \"maior que\"");
		printf("\n6. Sair");
		printf("\nDigite a opcao desejada: ");
		//pedir a opcao ao usuario
		scanf("%i", &opcao);
		
		//processar a opcao desejada
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("\nDigite um numero: ");
				scanf("%d", &temp);
				printf("\nDigite a posicao: ");
				scanf("%d", &posicao);
				inserir(temp, posicao);
				break;
			case 3:
				printf("\nDigite a posicao: ");
				scanf("%d", &posicao);
				temp = remover(posicao);
				printf("\nNumero removido: %d",
					temp);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("\nDigite o numero: ");
        scanf("%d", &temp);
        removerMaiorQue(temp);
				printf("\nNumero(s) removidos");
				break;
			case 6:
				printf("\nSaindo do programa...");
				break;
			default:
				printf("\nEscolha uma opcao valida!");
		}
		
	} while (opcao != 6);
	return 0;
}
