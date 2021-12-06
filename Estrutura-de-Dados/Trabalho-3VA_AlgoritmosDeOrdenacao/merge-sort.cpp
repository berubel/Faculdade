#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //10//100//1000//10000/100000

void merge_sort(int vector[], int initial, int final);
int fillVector(int v[], int n);
void printVector(int v[], int n);


int main() {
	
    clock_t t1, t2;
    int vector[SIZE];
	
    int initial = 0;
    int final = fillVector(vector, SIZE);
    //printVector(vector, SIZE);
    
    t1 = clock(); // tempo inicial
    printf("\nTempo de execucao antes do selection sort: %lf \n\n", ((double)t1)/((CLOCKS_PER_SEC/1000))); // milissegundos
    merge_sort(vector, initial, final);
    t2 = clock(); // tempo final
    printf("\nTempo de execucao apos o selection sort: %lf\n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
    t2 = t2 - t1; // tempo final - tempo inicial
    //printVector(vector, SIZE);
    printf("\nTempo de execucao do selection sort: %lf \n\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); // milissegundos
	
}

int fillVector(int v[], int n) { // Preenche o vetor
    srand(time(NULL));
    int final;
	for (int i=0; i<n; i++) {
		v[i] = rand() % 100 + 1;
        final = i;
	}
    return final;
}

void merge(int vector[], int initial, int mid, int final){ // Intercala a partir das divisões
	
	int size = final - initial +1; 
	int *w = (int*) malloc(size * sizeof(int));
	
	if (w == NULL) return;
	
	int i = initial, j = mid + 1, k = 0;
	
	while(i<=mid && j<=final){ // Enquanto vetor da primeira metade for maior que da segunda metade
		if(vector[i]<vector[j]){
			w[k++] = vector[i++];  // atribuir menor valor da posicao da primeira metade a w
			
		}else{
			w[k++] = vector[j++]; // atribuir menor valor da posicao da segunda metade a w
		}
	}
	
	while(i<=mid){ 
		w[k++] = vector[i++]; // caso sobrar elementos da primeira metade
	}
	while(j<=final){
		w[k++] = vector[j++]; // caso sobrar elementos da segunda metade
	}
	for(k=0; k<size; k++){
		vector[initial+k] = w[k]; // atribuir valores ordenados em w ao vetor
	}
}

void merge_sort(int vector[], int initial, int final){ // Ordena o vetor
	if(initial == final) return; 
	
	int mid = (initial+final)/2; 
	
	merge_sort(vector, initial, mid); // Primeira metade
	merge_sort(vector, mid+1, final); // Segunda metade
	
	merge(vector, initial, mid, final);
}

void printVector(int v[], int n) { // Printa o vetor
	for (int i=0; i<n; i++) {
		printf("%3d ", v[i]);
	}
	printf("\n");
}

