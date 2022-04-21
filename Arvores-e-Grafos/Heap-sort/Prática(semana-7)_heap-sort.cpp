//================================================================
//  2010840 - Gabriele Cardoso das Virgens

/*  Aula 7 - 13/04/2022
	ÁRVORES E GRAFOS

    ****** HEAPSORT ******
*/
//================================================================
 
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

// Constante para tamanho do vetor
#define max 10

// Protótipo da função de ordenação
void peneira(int *vet, int raiz, int fundo);
void heapsort(int *vet, int n);

//Função Main
int main() {
	setlocale(LC_ALL, "Portuguese");

	int i, vetor[max];
		 
	printf("######HEAPSORT######\n\n");
	 
	// Lê MAX ou 10 valores
	for(i = 0; i < max; i++){
		printf("Digite um valor: ");
		scanf("%d", &vetor[i]);
	}
	//Ordena os valores
	heapsort(vetor,max);
	
	// Imprime os valores ordenados
	printf("\nValores ordenados: \n\n");
	
	for (i = 0; i < max; i++) {
		printf("%d \n", vetor[i]);
	}
	return(0);
}
//Função heapsort
void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}
//Função para efetuar o "shift up"
void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

