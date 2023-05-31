#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define TAM_MAX 10

typedef struct _pilha {
	caixa vetor[TAM_MAX];
  double pesoTotal;
	int topo;
} pilha;

pilha p;

void inicializar(){
	p.topo = -1;
  p.pesoTotal = 0.0;
}

int verificarVazia(){
	if(p.topo == -1)
		return 1;
	else return 0;
}

int verificarCheia(){
	if(p.topo == TAM_MAX - 1)
		return 1;
	else return 0;
}

void push(caixa c){
  if (p.pesoTotal >= 100) {
		printf("\nNao eh possivel empilhar, peso maior ou igual a 100 kg.");
    return;
  }
	if(!verificarCheia()) {
		//atualizar topo
		p.topo++;
		//colocar o numero na posicao que topo indica
		p.vetor[p.topo] = c;
    p.pesoTotal += c.peso;
	} else {
		printf("\nNao eh possivel inserir, pilha cheia.");
	}
}

caixa pop(){
	caixa aux;
	if(!verificarVazia()) {
		//guarda o livro a ser removido em uma variavel
		aux = p.vetor[p.topo];
		//atualiza o topo
		p.topo--;
		//retorna o livro removido
    p.pesoTotal -= aux.peso;
		return aux;
	} else {
		printf("\nA pilha estah vazia.");
		aux.identificador = -1;
		return aux;
	}
}

void imprimir(){
	if(verificarVazia()) {
		printf("\nA pilha esta vazia.");
	} else {
		int i;
		printf("\nOs elementos na pilha sao:");
		for(i = p.topo; i >= 0; i--) {
			imprimirCaixa(p.vetor[i]);
      printf("\nPeso total: %.2lf kg", p.pesoTotal);
    }
	}
}

void imprimirCaixa(caixa c) {
	printf("\nIdentificador: %d \tDestino: %s \tPeso: %f",
		c.identificador, c.destino, c.peso);
}

caixa lerCaixa(){
	caixa aux;
	fflush(stdin);
	printf("\nDigite o identificador: ");
	scanf("%d", &aux.identificador);
	fflush(stdin);
	printf("Digite o destino: ");
	fgets(aux.destino, 50, stdin);
	printf("Digite o peso: ");
	scanf("%f", &aux.peso);
	return aux;
}
