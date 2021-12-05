#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000 //10//100//1000//10000/100000

void insertion_sort(int v[], int n);
void fillVector(int v[], int n);
void printVector(int v[], int n);


int main() {
	
    clock_t t1, t2;
	int vector[SIZE];

	fillVector(vector, SIZE);
    //printVector(vector, SIZE);

    t1 = clock(); // tempo inicial
    printf("\nTempo de execucao antes do insertion sort: %lf \n\n", ((double)t1)/((CLOCKS_PER_SEC/1000))); // milissegundos
    insertion_sort(vector, SIZE);
    t2 = clock(); // tempo final
    printf("\nTempo de execucao apos o insertion sort: %lf\n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
    t2 = t2 - t1; // tempo final - tempo inicial
	//printVector(vector, SIZE);
    printf("\nTempo de execucao do insertion sort: %lf \n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
	
}

void fillVector(int v[], int n) { // Preenche o vetor
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		v[i] = rand() % 100 + 1;
	}
}

void insert(int x, int v[], int n) { // Compara o atual com o anterior e troca caso for menor
	while (n>0 && x < v[n-1]) {
		v[n] = v[n-1];
		n--;
	}
	v[n] = x;
}

void insertion_sort(int v[], int n) { //Ordena o vetor
	
	for (int i=0; i<n; i++) {
		insert(v[i], v, i);
	}	
}

void printVector(int v[], int n) { // Printa o vetor
	for (int i=0; i<n; i++) {
		printf("%3d ", v[i]);
	}
	printf("\n");
}

