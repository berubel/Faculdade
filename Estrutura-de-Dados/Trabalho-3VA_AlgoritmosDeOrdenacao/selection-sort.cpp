#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000 //10//100//1000//10000/100000

void selection_sort(int v[], int n);
void fillVector(int v[], int n);
void printVector(int v[], int n);


int main() {
	
    clock_t t1, t2;
	int vector[SIZE];

	fillVector(vector, SIZE);
    //printVector(vector, SIZE);

    t1 = clock(); // tempo inicial
    printf("\nTempo de execucao antes do selection sort: %lf \n\n", ((double)t1)/((CLOCKS_PER_SEC/1000))); // milissegundos
    selection_sort(vector, SIZE);
    t2 = clock(); // tempo final
    printf("\nTempo de execucao apos o selection sort: %lf\n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
    t2 = t2 - t1; // tempo final - tempo inicial
	//printVector(vector, SIZE);
    printf("\nTempo de execucao do selection sort: %lf \n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
	
}

void fillVector(int v[], int n) { // Preenche o vetor
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		v[i] = rand() % 100 + 1;
	}
}

int select(int v[], int n) { // Seleciona o menor
	int i = 0;
	for (int j=1; j<n; j++) {
		if (v[i] < v[j]) {
			i = j;
		}
	}
	return i;
}

void selection_sort(int v[], int n) { // Ordena o vetor
	int aux;
	while (n>1) {	
		int k = select(v, n);
		aux = v[n-1];
		v[n-1] = v[select(v, n)];
		v[select(v, n)] = aux; 
				 
		n--;
	}
}

void printVector(int v[], int n) { // Printa o vetor
	for (int i=0; i<n; i++) {
		printf("%3d ", v[i]);
	}
	printf("\n");
}

