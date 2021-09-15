#include<stdio.h>
#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 6 - 14/09/2021
	ESTRUTURA DE DADOS

    ****** 	REVISÃO ******
*/

typedef struct list{
	struct product *first; //Ponteiro para apontar para primeiro da lista
	int size;
};

typedef struct product{
	int weight;
	double price;
	struct product *next; //Necessário ponteiro para apontar para proximo da lista
};

// Funções
product* createNewProduct (int weight, double price);
list* createNewList();

void addNewItem_First(int weight, double price, list *list);

bool verifyEmptyList(list *list);

void removeItem_First(list *list);
void removeItem_Last(list *list);

void printList(list *list);
void printProduct(product *product);

int getSize(list* list);
void getProduct(list * list, int index);

int main (){

    setlocale(LC_ALL, "Portuguese"); 
    
    list  *myList = createNewList(); //criando uma lista
    
	
	addNewItem_First(40, 32.21, myList);
	addNewItem_First(20, 45.77, myList);
	addNewItem_First(88, 74.11, myList);
	addNewItem_First(12, 3.00, myList);
	addNewItem_First(25, 99.22, myList);
	printList(myList);
	
	removeItem_First(myList);
	printList(myList);
	removeItem_Last(myList);
	printList(myList);
	
	printf("\n\nTamanho da Lista: %d", getSize(myList));
	getProduct(myList, 3);
    
    return 0;
}

product* createNewProduct (int weight, double price){
	product *newProduct =(product*) malloc(sizeof(product)); //É preciso fazer casting para passar o ponteiro de produto para o ponteiro void do malloc
    
    newProduct->weight = weight;
    newProduct->price = price;
    newProduct->next = NULL;
    
    return newProduct;
}

list* createNewList(){
		list *newList = (list *)malloc(sizeof(list)); //Ponteiro do tipo list
		
		newList->first = NULL;
		
}

void addNewItem_First(int weight, double price, list *list){
	product *newProduct = createNewProduct(weight, price);
	
	printf("\nWeight: %d \t Price: %.2f\n", newProduct->weight, newProduct->price);
	
	//Ajusta o ponteiro próximo
	newProduct->next = list->first; //O primeiro produto passa a ser novo próximo, e o produto adicionado sobe para primeiro da lista
	//Alterar indicador de inicio da lista
	list->first = newProduct; // o primeiro da lista passa a ser o adicionado mais recentemente
}
bool verifyEmptyList(list *list){
	
	if (list->first == NULL){
    	printf("\nLista Vazia\n\n");
	}else{
		//printf("\nExistem elementos na lista\n\n");
	}
	
	return list->first==NULL;
}
void printList(list *list){
	
	if (verifyEmptyList(list)){
    	printf("\nLista Vazia\n\n");
	}else{
		printf("\nMY LIST \n\n");
	
	}
	product *atual = list->first; // ponteiro atual do tipo produto que recebe o valor do primeiro da lista
	while (atual != NULL){
		printf("\nWeight: %d \t Price: %.2f\n", atual->weight, atual->price);
		atual = atual->next; //atual passa a receber o valor do proximo produto da lista até que a mesma acabe
	}
	
	
}
int getSize(list* list){
	return list->size;
}
void removeItem_First(list *list){
	if (verifyEmptyList(list)){
		printf("Lista vazia. Impossível  realizar exclusão!\n");
	}else{
		
		//Obter primeiro item
		product *first = list->first;
	
		//Transformar segundo item da lista em primeiro
		list->first = first->next; //proximo do primeiro produto passa a ser o primeiro da lista
	
		//Eliminar referencias do primerio
		first->next = NULL;
	
		//Liberar memoria
		free(first);
	
		//Diminuir tamanho da lista
		list->size--;
    }
}

void removeItem_Last(list *list){
	
	if (verifyEmptyList(list)){
		printf("Lista vazia. Impossível  realizar exclusão!\n");
	}else{
		//Obter primeiro item da lista
		product *atual = list->first;
		product *anterior = list->first;
		
		//Percorrer toda lista
		while(atual->next != NULL){ //enquanto não chegar ao final da lista
			anterior = atual; //anterior passa a receber valor do atual
			atual = atual->next; // atual recebe valor do proximo
		}
		//printProduct(atual); ULTIMO PRODUTO
		//printProduct(anterior); PENULTIMO PRODUTO
		
		//Exclusão
		if (anterior->next = NULL){ //se houver apenas um produto na lista
			list->first = NULL;
		}
		anterior->next = NULL;//proximo produto do penultimo, significa que chegou ao ultimo da lista, portanto remove-o e libera a memória
		free(atual);
		
		//Diminuir tamanho da lista
		list->size--;
    }
}

void printProduct(product *product){
	printf("\nWeight: %d \t Price: %.2f\n", product->weight, product->price);
	
}
void getProduct(list * list, int index){
	
	if(verifyEmptyList(list)){
		printf("\nLista não contém produtos \n");
	}else if(index <=0 || index >= getSize(list)){
		printf("\nIndice %d informado fora dos limites!! \n", index);
	}
	else{
		product *product = list->first;
		int i = 1;
		
		while (i<index && product->next){
			product = product->next;
			i++;
		}
		
		
		printProduct(product);
	}
	
	
	
}
