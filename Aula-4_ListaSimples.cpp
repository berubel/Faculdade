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
void printLista(lista *lista);

//Imprimir conta
void printConta(conta *conta, int index);

//Obter tamanho da lista
int getSize(lista* lista);

//Obter uma conta da lista
void getConta(lista * lista, int index);

//Obter dados da conta
void dadosConta(int *dia, int *mes, int *ano, double *valor, int *situacao);

int main (){

    setlocale(LC_ALL, "Portuguese"); 
    
    int op, opc;
    int dia, mes, ano;
    int posicao;
    double valor;
    bool situacao;
    
   lista  *listaDeContas = createNewLista();
    
    do {
    	
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
		
				dadosConta(&dia, &mes, &ano, &valor, &opc);
				
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			      
				inserirNoInicio(dia, mes, ano, valor, situacao, listaDeContas);	
			
			
			break;
			
			case 2:
			
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			      
				inserirNoInicio(dia, mes, ano, valor, situacao, listaDeContas);	
				
				
			break;
			
			
			case 3:
				
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			    
			    printf("\nDigite o número da posição que deseja inserir a conta: ");
			    scanf("%i", &posicao);
			      
			    inserirNoMeio(dia, mes, ano, valor, situacao, listaDeContas, posicao);
				
			break;
			
			case 4:
				
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			      
				inserirNoFinal(dia, mes, ano, valor, situacao, listaDeContas);	
				
			break;
			
			case 5:
			      
			   	removerDoInicio(listaDeContas);  
				
			break;
			
			case 6:
				
				printf("\nDigite o número da posição da conta que deseja remover: ");
			    scanf("%i", &posicao);
				removerDoMeio(listaDeContas, posicao); 
				
			break;
			
			case 7:
				
				removerDoFinal(listaDeContas);  
				
			break;
			
			case 8:
				
				printf("\nDigite o número da posição da conta que deseja visualizar: ");
			    scanf("%i", &posicao);
				getConta(listaDeContas, posicao);
				
			break;
			
			case 9:
			
				system("cls");
				printLista(listaDeContas);
				
			break;
	
		}
		printf("\n\nDeseja realizar nova operação? ");
		printf("\n(1) - SIM");
		printf("\n(2) - NÃO");
		printf("\nOPÇÃO: ");
		scanf("%i", &op);
	
		if (op==1){
			system("cls");
		}
		
	} while (op == 1);
    
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
	
	//Ajusta o ponteiro próximo
	newConta->next = lista->first; //O primeiro produto passa a ser novo próximo, e o produto adicionado sobe para primeiro da lista
	//Alterar indicador de inicio da lista
	lista->first = newConta; // o primeiro da lista passa a ser o adicionado mais recentemente
	
	lista->size++;
	
	system("cls");
	printf("\nAdicionada com sucesso!"); 
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
	    
	    lista->size++;
	    
	    system("cls");
		printf("\nAdicionada com sucesso!"); 
	}
}

void inserirNoMeio(int dia, int mes, int ano, double valor, bool situacao, lista *lista, int posicao){
	
	posicao = posicao - 1;
	
	if(verifyEmptyList(lista) || posicao == 0){
		
		inserirNoInicio(dia, mes, ano, valor, situacao, lista);
		
	}else{
			
		conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
		conta *atual = lista->first;	
	
	    int posicaoAtual = 1;
	    
	    while (posicaoAtual < posicao && atual->next != NULL){ //PERCORRE A LISTA, Procurando o próximo 
           				
                atual = atual->next;
           		posicaoAtual++;
		}
		newConta->next = atual->next;
		atual->next = newConta;
		
		lista->size++;
		
		system("cls");
		printf("\nAdicionada com sucesso!"); 
        	
		if (posicao > posicaoAtual){
			
			inserirNoFinal(dia, mes, ano, valor, situacao, lista);
			
		}
	}
}
void removerDoInicio(lista *lista){
	
	if (verifyEmptyList(lista)){
		
		printf("Impossível realizar exclusão!\n");
		
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
		lista->size = lista->size --;
		
		system("cls");
		printf("\nRemovida com sucesso!"); 
    }
}

void removerDoFinal(lista *lista){
	
	if (verifyEmptyList(lista)){	
	
		printf("Impossível realizar exclusão!\n");	
			
    }else{
    	
    	//Obter primeiro item da lista
		conta *atual = lista->first;
		conta *anterior = lista->first;
		
		//Exclusão se houver apenas um produto na lista
		if (atual->next == NULL){
			removerDoInicio(lista);
		}
	
		//Percorrer toda lista
		while(atual->next != NULL){ //enquanto não chegar ao final da lista
			anterior = atual; //anterior passa a receber valor do atual
			atual = atual->next; // atual recebe valor do proximo
		}	
		//Exclusão
		
		//Ajusta o ponteiro proximo
		anterior->next = NULL;//proximo produto do penultimo, significa que chegou ao ultimo da lista, portanto remove-o e libera a memória. 
		free(atual);
					
		//Diminuir tamanho da lista
		lista->size --;
		
		system("cls");
		printf("\nRemovida com sucesso!"); 
	}  		
}

void removerDoMeio(lista *lista, int posicao){
	
	posicao = posicao;
	
	if(verifyEmptyList(lista)){
		
		printf("Impossível realizar exclusão!\n");	
		
	}else{
		
		int posicaoAtual = 1;
		
		conta *atual = lista->first;
		conta *anterior = lista->first;	
		
			
		if (posicao == 1){
			
			removerDoInicio(lista);
			
		}else{
			
			while (posicaoAtual < posicao || posicaoAtual == 1 && posicao != 1 && atual->next != NULL){ //PERCORRE A LISTA, Procurando o próximo 
           		
					anterior = atual;		
                	atual = atual->next;
           		    posicaoAtual++;     	
			}

			if (posicao > posicaoAtual || posicao <= 0){
					
				printf("\nPosição %d informada fora dos limites da lista!! \n", posicao);
				printf("Impossível realizar exclusão!\n");	 
					
			} else if (atual->next == NULL){
					
						removerDoFinal(lista);
							
			}else{
					
				anterior->next = atual->next;
				atual = NULL;
		
				free(atual);
		
   				lista->size --;
		
				system("cls");
				printf("\nRemovida com sucesso!"); 	
					
			}				
		}
	}	   
}

bool verifyEmptyList(lista *lista){
	
	if (lista->first == NULL){
		
		system("cls");
    	printf("\nLista Vazia\n\n");
	}
		
	return lista->first==NULL;
}

void printLista(lista *lista){
	
	if (verifyEmptyList(lista)){
		
	}else{
		
		printf("\nMINHA LISTA DE CONTAS \n\n");
	
	}
	conta *atual = lista->first; // ponteiro atual do tipo produto que recebe o valor do primeiro da lista
	int i = 1;
	
	while (atual != NULL){
		
		printConta(atual, i)  ;
		atual = atual->next; //atual passa a receber o valor do proximo produto da lista até que a mesma acabe
		i++;
	}
	
	
}

void printConta(conta *conta, int index){
	
	printf("CONTA %i", index);
	printf("\nVencimento: %i/%i/%i \nValor: R$ %d \nSituação: %s\n\n", conta->dia, conta->mes, conta->ano, conta->valor, conta->situacao?"Paga":"Não paga");
	
}

int getSize(lista* lista){
	
	lista->size = sizeof(lista);
	
	return lista->size;
}


void getConta(lista *lista, int index){
	
	conta *atual = lista->first;
	int i= 1;
	
	if(verifyEmptyList(lista)){
			
    }else{
	
		while (atual != NULL){
			
			atual = atual->next;
			i++;	
		}
	
		if (index>=i || index<=0){	
			
			system("cls");
			printf("\nIndice %d informado fora dos limites!! \n", index);
		}
	
	}if (index < i && index !=0){
	
		i = 1;
		atual = lista->first;
		
		while (i<index && atual != NULL){
					
			atual = atual->next;
			i++;
		}
		
		system("cls");
		printConta(atual, index);
	}
}

void dadosConta(int *dia, int *mes, int *ano, double *valor, int *situacao){
	
		int opc;
		int auxDia, auxMes, auxAno;
		double auxValor;
	
		printf("\n\nInsira a data de vencimento: ");
		printf("\n\nDia: ");
		scanf("%i", &auxDia);
		(*dia) = auxDia;
    	printf("\nMês: ");
		scanf("%i", &auxMes);
		(*mes) = auxMes;
		printf("\nAno: ");
		scanf("%i", &auxAno);
		(*ano) = auxAno;
		printf("\nInsira o valor da conta: R$ ");
		scanf("%d", &auxValor);
		(*valor) = auxValor;
		printf("\nInsira a situção da conta: ");
		printf("\n(1) - PAGA");
		printf("\n(2) - NÃO PAGA");
		printf("\nOPÇÃO: ");
		scanf("%i", &opc);
		(*situacao) = opc;				
}
