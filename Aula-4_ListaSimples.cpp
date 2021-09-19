#include<stdio.h>
#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<stdbool.h>

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 4 - 18/09/2021
	ESTRUTURA DE DADOS

    ****** Implementação de listas encadeadas simples ******
*/

typedef struct conta{
	int dia;
	int mes;
	int ano;
	double valor;
	bool situacao;
	struct conta *next;	
};

typedef struct lista{
	struct conta *first;
	int size;
};

// FUNÇÕES

//Criar conta 
conta* createNewConta (int dia, int mes, int ano, double valor, bool situacao);

//Criar lista
lista* createNewLista();

//Adicionar na lista
void inserirNoInicio(int dia, int mes, int ano, double valor, bool situacao, lista *lista);
void inserirNoFinal(int dia, int mes, int ano, double valor, bool situacao, lista *lista);
void inserirNoMeio(int dia, int mes, int ano, double valor, bool situacao, lista *lista, int posicao);

//Verificar se a lista está vazia
bool verifyEmptyList(lista *lista);

//Remover da lista
void removerDoInicio(lista *lista);
void removerDoFinal(lista *lista);
void removerDoMeio(lista *lista, int posicao);

//Imprimir lista
void printList(lista *lista);

//Imprimir conta
void printConta(conta *conta);

//Obter tamanho da lista
int getSize(lista* lista);

//Obter uma conta da lista
void getConta(lista * lista, int index);

//Obter dados da conta
void dadosConta(int *dia, int *mes, int *ano, double *valor, bool situacao);

int main (){

    setlocale(LC_ALL, "Portuguese"); 
    
    int op, opc;
    int dia, mes, ano;
    double valor;
    bool situacao;
    
   lista  *listaDeContas = createNewLista();
    
    printf("LISTA DE CONTAS");
    printf("\n\nMenu:");
    printf("\n\n(1) - Inserir nova conta");
    printf("\n(2) - Inserir nova conta no início da lista");
    printf("\n(3) - Inserir nova conta no meio da lista");
    printf("\n(4) - Inserir nova conta no final da lista");
    printf("\n(5) - Remover conta do início da lista");
    printf("\n(6) - Remover conta do meio da lista");
    printf("\n(7) - Remover conta do final da lista");
    printf("\n(8) - Obter uma conta da lista");
    printf("\n(9) - Imprimir lista\n\n");
    printf("OPÇÃO: ");
    scanf("%i",&op);
    
    
    switch(op){
		
		case 1:
			
			printf("\n\nInsira a data de vencimento: ");
			printf("\n\nDia: ");
			scanf("%i", &dia);
    		printf("\nMês: ");
			scanf("%i", &mes);
			printf("\nAno: ");
			scanf("%i", &ano);
			printf("\nInsira o valor da conta: ");
			scanf("%d", &valor);
			printf("\nInsira a situção da conta: ");
			printf("\n(1) - PAGA");
			printf("\n(2) - NÃO PAGA");
			printf("\nOPÇÃO: ");
			scanf("%i", &opc);
			
			if (opc == 1){
				situacao = true;
			}else
			      situacao = false;
			
			inserirNoInicio(dia, mes, ano, valor, situacao, listaDeContas);	
			
			
		break;
		
	
	}
    
    
    
    return 0;
}

conta* createNewConta (int dia, int mes, int ano, double valor, bool situacao){
	conta *newConta =(conta*) malloc(sizeof(conta)); //É preciso fazer casting para passar o ponteiro de produto para o ponteiro void do malloc
    
    newConta->dia = dia;
    newConta->mes = mes;
    newConta->ano = ano;
    newConta->valor = valor;
    newConta->situacao = situacao;
    newConta->next = NULL;
    
    return newConta;
}

lista* createNewLista(){
		lista *newLista = (lista *)malloc(sizeof(lista)); //Ponteiro do tipo lista
		
		newLista->first = NULL;
		
}

void inserirNoInicio(int dia, int mes, int ano, double valor, bool situacao, lista *lista){
	conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
	
	printf("\nDia: %i \nMês: %i \nAno: %i \nValor: %d \nSituação: %s\n", newConta->dia, newConta->mes, newConta->ano, newConta->valor, newConta->situacao?"true":"false");
	
	//Ajusta o ponteiro próximo
	newConta->next = lista->first; //O primeiro produto passa a ser novo próximo, e o produto adicionado sobe para primeiro da lista
	//Alterar indicador de inicio da lista
	lista->first = newConta; // o primeiro da lista passa a ser o adicionado mais recentemente
}
void inserirNoFinal(int dia, int mes, int ano, double valor, bool situacao, lista *lista){ 
	
	conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
	
	conta *atual = lista->first;
	
    if(verifyEmptyList(lista)){
     	lista->first = newConta;
	}else{
	    while (atual->next != NULL){ //PERCORRE A LISTA, Procurando o próximo
           		atual = atual->next; 
	   	}
	    atual->next = newConta;
	}
}

void inserirNoMeio(int dia, int mes, int ano, double valor, bool situacao, lista *lista, int posicao){
	
	if(verifyEmptyList(lista) || posicao == 1){
		
		inserirNoInicio(dia, mes, ano, valor, situacao, lista);
		
	} else {
			
		conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
		conta *atual = lista->first;
	    int posicaoAtual = 1;
	    
	    while (atual->next != NULL){ //PERCORRE A LISTA, Procurando o próximo 
           		
           		printf("Posição: %d\n", posicaoAtual);
           		
           		if(posicaoAtual == posicao -1){
           			newConta->next = atual->next;
           			atual->next = newConta;
           			
				}
                atual = atual->next;
           		posicaoAtual++;
		}	
		
		if (posicao > posicaoAtual){
			inserirNoFinal(dia, mes, ano, valor, situacao, lista);
		}
	}
}
void removerDoInicio(lista *lista){
	
	if (verifyEmptyList(lista)){
		printf("Lista vazia. Impossível  realizar exclusão!\n");
	}else{
		
		//Obter primeiro item
		conta *first = lista->first;
	
		//Transformar segundo item da lista em primeiro
		lista->first = first->next; //proximo do primeiro produto passa a ser o primeiro da lista
	
		//Eliminar referencias do primerio
		first->next = NULL;
	
		//Liberar memoria
		free(first);
	
		//Diminuir tamanho da lista
		lista->size--;
    }
}

void removerDoFinal(lista *lista){
	
	if (verifyEmptyList(lista)){
		printf("Lista vazia. Impossível  realizar exclusão!\n");
	}else{
		//Obter primeiro item da lista
		conta *atual = lista->first;
		conta *anterior = lista->first;
		
		//Percorrer toda lista
		while(atual->next != NULL){ //enquanto não chegar ao final da lista
			anterior = atual; //anterior passa a receber valor do atual
			atual = atual->next; // atual recebe valor do proximo
		}
		//printProduct(atual); ULTIMO PRODUTO
		//printProduct(anterior); PENULTIMO PRODUTO
		
		//Exclusão
		if (anterior->next = NULL){ //se houver apenas um produto na lista
			lista->first = NULL;
		}
		anterior->next = NULL;//proximo produto do penultimo, significa que chegou ao ultimo da lista, portanto remove-o e libera a memória
		free(atual);
		
		//Diminuir tamanho da lista
		lista->size--;
    }
}

bool verifyEmptyList(lista *lista){
	
	if (lista->first == NULL){
    	printf("\nLista Vazia\n\n");
	}else
		printf("\nExistem elementos na lista\n\n");
		
	return lista->first==NULL;
}

void printLista(lista *lista){
	
	if (verifyEmptyList(lista)){
    	printf("\nLista Vazia\n\n");
	}else{
		printf("\nMINHA LISTA DE CONTAS \n\n");
	
	}
	conta *atual = lista->first; // ponteiro atual do tipo produto que recebe o valor do primeiro da lista
	while (atual != NULL){
		printf("\nDia: %i \nMês: %i \nAno: %i \nValor: %d \nSituação: %b", atual->dia, atual->mes, atual->ano, atual->valor, atual->situacao);
		atual = atual->next; //atual passa a receber o valor do proximo produto da lista até que a mesma acabe
	}
	
	
}

void printConta(conta *conta){
	printf("\nDia: %i \nMês: %i \nAno: %i \nValor: %d \nSituação: %b", conta->dia, conta->mes, conta->ano, conta->valor, conta->situacao);
	
}

int getSize(lista* lista){
	return lista->size;
}


void  getConta(lista * lista, int index){
	
	if(verifyEmptyList(lista)){
		printf("\nLista não contém contas \n");
	}else if(index <=0 || index >= getSize(lista)){
		printf("\nIndice %d informado fora dos limites!! \n", index);
	}
	else{
		conta *conta = lista->first;
		int i = 1;
		
		while (i<index && conta->next){
			conta = conta->next;
			i++;
		}
		
		
		printConta(conta);
	}
}

void dadosConta(int *dia, int *mes, int *ano, double *valor, bool situacao){
			int opc;
	
			printf("\n\nInsira a data de vencimento: ");
			printf("\nDia: ");
			scanf("%i", &dia);
    		printf("\nMês: ");
			scanf("%i", &mes);
			printf("\nAno: ");
			scanf("%i", &ano);
			printf("\nInsira o valor da conta: ");
			scanf("%d", &valor);
			printf("\nInsira a situção da conta: ");
			printf("\n(1) - PAGA");
			printf("\n(2) - NÃO PAGA");
			printf("\nOPÇÃO: ");
			scanf("%i", &opc);
			
			if (opc == 1){
				situacao = true;
			}else
			      situacao = false;
			
	
}
