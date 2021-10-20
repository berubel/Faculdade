#include<stdio.h>
#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<string>

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 11 - 19/10/2021
	Estrutura de Dados

    ****** ESCALONADOR DE PROCESSOS POR PRIORIDADE ******
       
*/

typedef struct Processos{
	int PID;
	char nome [255];
	struct Processos *proximo;
};

typedef struct ListaMaiorPrioridade{
	struct Processos *inicio;
	struct Processo *fim;
	int size;
};

typedef struct ListaMenorPrioridade{
	struct Processos *inicio;
	struct Processo *fim;
	int size;
};

Processos* criarNovoProcesso (char nome [], int id);
void criarListaVazia();
void adicionarProcesso(Processos *processo);
void executarProcesso(ListaMaiorPrioridade *lista);
void moverProcesso(int id);
void finalizarProcesso(ListaMaiorPrioridade *lista);
void finalizarProcessoEspecifico(int id);
void obterProcesso(int id);
void printLista(int op);

int main (){

    setlocale(LC_ALL, "Portuguese"); 
    
    // ListaMaiorPrioridade *listaMaiorP = criarListaVazia();
    //ListaMenorPrioridade *listaMenorP = criarListaVazia();
     
     int op;
    
    do {
    	
    	printf("ESCALONADOR DE PROCESSOS POR PRIORIDADE");
   	 	printf("\n\nMenu:");
    	printf("\n\n(1) - Adicionar processo");
    	printf("\n(2) - Executar processo");
    	printf("\n(3) - Mover processo");
    	printf("\n(4) - Finalizar processo");
    	printf("\n(5) - Finalizar processo específico");
    	printf("\n(6) - Obter um processo");
    	printf("\n(7) - Imprimir lista\n\n");
    	printf("OPÇÃO: ");
    	scanf("%i",&op);
    
    	do{
			printf("\n\nDeseja realizar nova operação? ");
			printf("\n(1) - SIM");
			printf("\n(2) - NÃO");
			printf("\nOPÇÃO: ");
			scanf("%i", &op);
			
			if (op < 1|| op > 2){
				printf("\n\nOpção inválida!");
			}
		
		}while(op < 1 || op > 2);
		
		if (op == 1){
			system("cls");
		}
		
	} while (op == 1);
    
    
    return 0;
}
