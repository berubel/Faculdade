#include<stdio.h>
#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include <stdbool.h>

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 11 - 19/10/2021
	Estrutura de Dados

    ****** ESCALONADOR DE PROCESSOS POR PRIORIDADE ******
       
*/

//typedef enum { false, true } bool;

typedef struct Processos
{
	int PID;
	char nome [];
	struct Processos *proximo;
};

typedef struct ListaMaiorPrioridade
{
	struct Processos *inicio;
	struct Processos *fim;
	int size;
};

typedef struct ListaMenorPrioridade
{
	struct Processos *inicio;
	struct Processos *fim;
	int size;
};

Processos* criarNovoProcesso (char nome [], int id);
ListaMaiorPrioridade* criarListaMaiorPVazia();
ListaMenorPrioridade* criarListaMenorPVazia();
void adicionarProcesso(char nome [], int id, int opc);
void executarProcesso(ListaMaiorPrioridade *lista);
void moverProcesso(int id);
void finalizarProcesso(ListaMaiorPrioridade *lista);
void finalizarProcessoEspecifico(int id);
void obterProcesso(int id);
void printLista(int op);
void dadosProcesso(int *id, char nome[]);

int main ()
{
    setlocale(LC_ALL, "Portuguese"); 
    
    ListaMaiorPrioridade *listaMaiorP = criarListaMaiorPVazia();
    ListaMenorPrioridade *listaMenorP = criarListaMenorPVazia();
     
    int op;
    int opc;
    int id;
    char nome[255];
    
    do 
	{
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
    	
    	switch (op)
		{
			case 1:
				 
				 dadosProcesso(&id, &nome[255]);
				 printf("\n\nProcesso prioritário?\n1 - SIM\n2 - NÃO");
				 scanf("%i", opc);
				 system("PAUSE");
				 
		}
    
    	do
		{
			printf("\n\nDeseja realizar nova operação? ");
			printf("\n(1) - SIM");
			printf("\n(2) - NÃO");
			printf("\nOPÇÃO: ");
			scanf("%i", &op);
			
			if (op < 1|| op > 2)
			{
				printf("\n\nOpção inválida!");
			}
				
		}while(op < 1 || op > 2);
		
		if (op == 1)
		{
			system("cls");
		}
			
	} while (op == 1);
      
    return 0;
}

ListaMaiorPrioridade* criarListaMaiorPVazia()
{
	ListaMaiorPrioridade *newListaMaiorP = (ListaMaiorPrioridade *)malloc(sizeof(ListaMaiorPrioridade)); 
		
	newListaMaiorP->inicio = NULL;
	newListaMaiorP->fim = NULL;
	newListaMaiorP->size = 0;
}

ListaMenorPrioridade* criarListaMenorPVazia()
{
	ListaMenorPrioridade *newListaMenorP = (ListaMenorPrioridade *)malloc(sizeof(ListaMenorPrioridade)); 
		
	newListaMenorP->inicio = NULL;
	newListaMenorP->fim = NULL;
	newListaMenorP->size = 0;
}

Processos* criarNovoProcesso (char nome [], int id)
{
	Processos *newProcesso = (Processos *)malloc(sizeof(Processos));
	
	return newProcesso;
}

void dadosProcesso(int *id, char nome[])
{	
	printf("\n\nNome: ");
	scanf("%s", nome);
	printf("\nPID: ");
	scanf("%i", id);			
}

