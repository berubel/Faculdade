#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //10//100//1000//10000/100000

void bubble_sort(int v[], int n);
void fillVector(int v[], int n);
void printVector(int v[], int n);


int main() {
	
    clock_t t1, t2;
	int vector[SIZE];

	fillVector(vector, SIZE);
    //printVector(vector, SIZE);

    t1 = clock(); // tempo inicial
    printf("\nTempo de execucao antes do bubble sort: %lf \n\n", ((double)t1)/((CLOCKS_PER_SEC/1000))); // milissegundos
    bubble_sort(vector, SIZE);
    t2 = clock(); // tempo final
    printf("\nTempo de execucao apos o bubble sort: %lf\n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
    t2 = t2 - t1; // tempo final - tempo inicial
	//printVector(vector, SIZE);
    printf("\nTempo de execucao do bubble sort: %lf \n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
	
}

void fillVector(int v[], int n) { // Preenche o vetor
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		v[i] = rand() % 100 + 1;
	}
}

void bubble_sort(int v[], int n) { // Ordena o vetor
	int aux, swap=0;
	
	for (int i=1; i <= n-1; i++) {
		for (int j=0; j < n-1; j++) {
			if (v[j] > v[j+1]) {
				aux = v[j+1];
				v[j+1] = v[j];
				v[j] = aux;	
				swap++;
			}
			
		}
	}
}

void printVector(int v[], int n) { // Printa o vetor
	for (int i=0; i<n; i++) {
		printf("%3d ", v[i]);
	}
	printf("\n");
}

