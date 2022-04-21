//================================================================
//  2010840 - Gabriele Cardoso das Virgens

/*  Aula 6 - 13/04/2022
	�RVORES E GRAFOS

    ****** QUICKSORT ******
*/
//================================================================
 
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
 
// Constante para tamanho do vetor
#define MAX 10
 
// Prot�tipo da fun��o de ordena��o
void quick_sort(int *a, int left, int right);
 
// Fun��o main
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int i, vet[MAX];
	 
	printf("######QUICK SORT######\n\n");
	 
	 // L� MAX ou 10 valores
	for(i = 0; i < MAX; i++){
		printf("Digite um valor: ");
		scanf("%d", &vet[i]);
	}
	 
	// Ordena os valores
	quick_sort(vet, 0, MAX - 1);
	 
	// Imprime os valores ordenados
	printf("\nValores ordenados: \n\n");
	 
	for(i = 0; i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	system("pause");
	return 0;
}
 
// Fun��o Quick Sort
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left; //baixo
    j = right; //alto
    x = a[(left + right) / 2]; // divis�o do vetor na metade
     
    while(i <= j) {
        while(a[i] < x && i < right) { //enquanto i for menor que o baixo
            i++; //incrementa o baixo
        }
        while(a[j] > x && j > left) { //enquanto j for maior que o alto
            j--; //decrementa o alto
        }
        if(i <= j) { //baixo � menor que o alto? Se sim, trocam de lugar
            y = a[i]; //vari�vel tempor�ria
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) { //parti��o da esquerda
        quick_sort(a, left, j);
    }
    if(i < right) { //parti��o da direita
        quick_sort(a, i, right);
    }
}
