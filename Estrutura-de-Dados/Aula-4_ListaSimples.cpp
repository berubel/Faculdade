#include<stdio.h>
#include<iostream>
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
    
    int op, opc, start;
    int dia, mes, ano;
    int posicao;
    double valor;
    bool situacao;
    
    lista  *listaDeContas = createNewLista();
    
    do {
    	
    	printf("LISTA DE CONTAS");
   	 	printf("\n\nMenu:");
    	printf("\n\n(1) - Inserir nova conta no início da lista");
    	printf("\n(2) - Inserir nova conta no meio da lista");
    	printf("\n(3) - Inserir nova conta no final da lista");
    	printf("\n(4) - Remover conta do início da lista");
    	printf("\n(5) - Remover conta do meio da lista");
    	printf("\n(6) - Remover conta do final da lista");
    	printf("\n(7) - Obter uma conta da lista");
    	printf("\n(8) - Imprimir lista\n\n");
    	printf("OPÇÃO: ");
    	scanf("%i",&op);
    
    
    	switch(op){
		
			case 1: //INSERIR CONTA NO INÍCIO
			
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			      
				inserirNoInicio(dia, mes, ano, valor, situacao, listaDeContas);	
				
				
			break;
			
			
			case 2: //INSERIR CONTA NO MEIO
				
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			    
			    printf("\nDigite o número da posição que deseja inserir a conta: ");
			    scanf("%i", &posicao);
			      
			    inserirNoMeio(dia, mes, ano, valor, situacao, listaDeContas, posicao);
				
			break;
			
			case 3: //INSERIR CONTA NO FINAL
				
				dadosConta(&dia, &mes, &ano, &valor, &opc);
			
				if (opc == 1){
					situacao = true;
				}else
			      situacao = false;
			      
				inserirNoFinal(dia, mes, ano, valor, situacao, listaDeContas);	
				
			break;
			
			case 4: //REMOVER CONTA DO INÍCIO
			      
			   	removerDoInicio(listaDeContas);  
				
			break;
			
			case 5: //REMOVER CONTA DO MEIO
				
				printf("\nDigite o número da posição da conta que deseja remover: ");
			    scanf("%i", &posicao);
				removerDoMeio(listaDeContas, posicao); 
				
			break;
			
			case 6: //REMOVER CONTA DO FINAL
				
				removerDoFinal(listaDeContas);  
				
			break;
			
			case 7: //OBTER UMA CONTA
				
				printf("\nDigite o número da posição da conta que deseja visualizar: ");
			    scanf("%i", &posicao);
				getConta(listaDeContas, posicao);
				
			break;
			
			case 8: //IMPRIMIR LISTA
			
				system("cls");
				printLista(listaDeContas);
				
			break;
			
			default: 
					
				printf("\nOpção inválida!");
			
			
		}
		
		do{
			printf("\n\nDeseja realizar nova operação? ");
			printf("\n(1) - SIM");
			printf("\n(2) - NÃO");
			printf("\nOPÇÃO: ");
			scanf("%i", &op);
			
			if (op < 1|| op > 2){
				printf("\n\nOpção inválida!");
			}
		
		}while(op < 1|| op > 2);
		
		if (op == 1){
			system("cls");
		}
		
	} while (op == 1);
    
    return 0;
}

conta* createNewConta (int dia, int mes, int ano, double valor, bool situacao){
	
	conta *newConta =(conta*) malloc(sizeof(conta)); 
    
    newConta->dia = dia;
    newConta->mes = mes;
    newConta->ano = ano;
    newConta->valor = valor;
    newConta->situacao = situacao;
    newConta->next = NULL;
    
    return newConta;
}

lista* createNewLista(){
	
	lista *newLista = (lista *)malloc(sizeof(lista)); 
		
	newLista->first = NULL;
		
}

void inserirNoInicio(int dia, int mes, int ano, double valor, bool situacao, lista *lista){
	
	//Criar nova conta
	conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
	
	//Ajusta o ponteiro próximo
	newConta->next = lista->first; //primeiro da lista passa a ser o próximo da nova conta, ou seja o segundo da lista
	
	//Altera indicador de inicio da lista
	lista->first = newConta; //nova conta passa a ser a primeira da lista
	
	//Aumenta tamanho da lista
	lista->size++;
	
	system("cls");
	printf("\nAdicionada com sucesso!"); 
}

void inserirNoFinal(int dia, int mes, int ano, double valor, bool situacao, lista *lista){ 
	
	//Criar nova conta
	conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
	
	//Obter primeiro da lista
	conta *atual = lista->first;
	
    if(verifyEmptyList(lista)){ //Verifica se a lista está vazia
    	
     	lista->first = newConta;
     	
	}else{
		//Percorre a lista
	    while (atual->next != NULL){ //Procurando a última conta
	    
           		atual = atual->next; 
	   	}
	   	//Adiciona nova conta na última posição
	    atual->next = newConta;
	    //Aumenta tamanho da lista
	    lista->size++;
	    
	    system("cls");
		printf("\nAdicionada com sucesso!"); 
	}
}

void inserirNoMeio(int dia, int mes, int ano, double valor, bool situacao, lista *lista, int posicao){
	
	posicao = posicao - 1;
	
	if(verifyEmptyList(lista) || posicao == 0){ //Verifica se a lista está vazia
		
		inserirNoInicio(dia, mes, ano, valor, situacao, lista);
		
	}else{
		
		//Criar nova conta	
		conta *newConta = createNewConta(dia, mes, ano, valor, situacao);
		
		//Obter primeiro da lista
		conta *atual = lista->first;	
	
	    int posicaoAtual = 1;
	    
	    //Percorre a lista
	    while (posicaoAtual < posicao && atual->next != NULL){ // Até a posição informada 
           				
                atual = atual->next;
           		posicaoAtual++;
		}
		//Ajusta ponteiro próximo para conta presente na posição informada
		newConta->next = atual->next;
		
		//Conta da posiçao informada passa a ser a nova conta
		atual->next = newConta;
		
		//Aumenta tamanho da lista
		lista->size++;
		
		system("cls");
		printf("\nAdicionada com sucesso!"); 
        	
		if (posicao > posicaoAtual){ //Se a posição informada for maior que a lista
			
			inserirNoFinal(dia, mes, ano, valor, situacao, lista);
			
		}
	}
}
void removerDoInicio(lista *lista){
	
	if (verifyEmptyList(lista)){ //Verifica se a lista está vazia
		
		printf("Impossível realizar exclusão!\n");
		
	}else{
		
		//Obter primeiro item
		conta *first = lista->first;
	
		//Transformar segundo item da lista em primeiro
		lista->first = first->next; 
	
		//Eliminar referências do primerio
		first->next = NULL;
	
		//Liberar memória
		free(first);
	
		//Diminuir tamanho da lista
		lista->size = lista->size --;
		
		system("cls");
		printf("\nRemovida com sucesso!"); 
    }
}

void removerDoFinal(lista *lista){
	
	if (verifyEmptyList(lista)){ //Verifica se a lista está vazia
	
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
		anterior->next = NULL;//próximo produto do penúltimo, ou seja o último, portanto remove-o e libera a memória. 
		free(atual);
					
		//Diminuir tamanho da lista
		lista->size --;
		
		system("cls");
		printf("\nRemovida com sucesso!"); 
	}  		
}

void removerDoMeio(lista *lista, int posicao){
	
	if(verifyEmptyList(lista)){ //Verifica se a lista está vazia
		
		printf("Impossível realizar exclusão!\n");	
		
	}else{
		
		int posicaoAtual = 1;
		
		//Obter primeiro da lista
		conta *atual = lista->first;
		conta *anterior = lista->first;	
			
		if (posicao == 1){ // Para remover o primeiro da lista
			
			removerDoInicio(lista);
			
		}else{
			//Percorre a lista
			while (posicaoAtual < posicao && atual->next != NULL){ //Até a posição informada
           		
					anterior = atual;		
                	atual = atual->next;
           		    posicaoAtual++; 
					       	
			}

			if (posicao > posicaoAtual || posicao <= 0){ // Posição inexistente
			
				system("cls");	
				printf("\nPosição %d informada fora dos limites da lista!! \n", posicao);
				printf("Impossível realizar exclusão!\n");	 
					
			} else if (atual->next == NULL){ // Para remover se a posição informada for a última da lista
					
						removerDoFinal(lista);
							
			}else{
				//Ajustar o ponteiro próximo	
				anterior->next = atual->next; //Ponteiro passa a apontar para a conta seguinte a atual (posição que será apagada)
				
				//Eliminar referências 
				atual = NULL;
				
		   		//Liberar a memória
				free(atual);
				
		        //Diminuir tamanho da lista
   				lista->size --;
		
				system("cls");
				printf("\nRemovida com sucesso!"); 	
					
			}				
		}
	}	   
}

bool verifyEmptyList(lista *lista){
	
	if (lista->first == NULL){ //Sem conta na primeira posição da lista
		
		system("cls");
    	printf("\nLista Vazia\n\n");
	}
		
	return lista->first==NULL;
}

void printLista(lista *lista){
	
	if (verifyEmptyList(lista)){ //Verifica se a lista está vazia
		
	}else{
		
		printf("\nMINHA LISTA DE CONTAS \n\n");
	
	}
	conta *atual = lista->first; // ponteiro atual do tipo conta que recebe o valor do primeiro da lista
	int i = 1;
	
	while (atual != NULL){ //Percorre a lista toda, até a última conta
		
		printConta(atual, i); //Imprimi a conta da posição i
		atual = atual->next; //atual passa a receber o valor da próxima conta da lista 
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
	
	if(verifyEmptyList(lista)){ // Verifica se a lista está vazia
			
    }else{
	
		while (atual != NULL){//Percorre a lista
			
			atual = atual->next;
			
			i++;	
		}
	
		if (index>=i || index<=0){	//Posição inexistente
			
			system("cls");
			printf("\nIndice %d informado fora dos limites!! \n", index);
			
		}else if (index < i && index !=0){ //Obtém a conta
	
			i = 1;
			atual = lista->first;
		
			while (i<index && atual != NULL){ //Percorre toda lista, até chegar na posição informada
					
				atual = atual->next;
				i++;
			}
		
			system("cls");
			printConta(atual, index); //Imprimi a conta
		}	
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
