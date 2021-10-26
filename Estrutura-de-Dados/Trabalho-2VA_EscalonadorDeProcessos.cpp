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

typedef struct Processos
{
	int PID;
	std::string *nome;
	struct Processos *anterior;
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

Processos* criarNovoProcesso (std::string& nome, int id);
ListaMaiorPrioridade* criarListaMaiorPVazia();
ListaMenorPrioridade* criarListaMenorPVazia();
void adicionarProcesso(std::string& nome, int id, int opc, ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa);
void executarProcesso(ListaMaiorPrioridade *lista);
void moverProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int id);
void finalizarProcesso(ListaMaiorPrioridade *lista);
void finalizarProcessoEspecifico(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int id);
void obterProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
void printProcesso(Processos *processo, int index);
void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
std::string dadosProcesso(int *id, std::string& nome);
bool verificarListaVazia(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
int obterTipoProcesso();

int n = 1;

int main ()
{
    setlocale(LC_ALL, "Portuguese"); 
    
    ListaMaiorPrioridade *listaMaiorP = criarListaMaiorPVazia();
    ListaMenorPrioridade *listaMenorP = criarListaMenorPVazia();
     
    int op;
    int opc;
    int id;
	std::string nome;

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
		//std::cin >> op;
    	
    	switch (op)
		{
			case 1:
				 
				dadosProcesso(&id, nome);
				opc = obterTipoProcesso();
				//printf("%i", opc);
				//std::cout<<nome;
				adicionarProcesso(nome, id, opc, listaMenorP, listaMaiorP);
				
				break;
			
			case 7:
				
				printf("\n\nQual lista deseja visualizar: \n1 - Processos Prioritários\n2 - Processos Simples");
				printf("\nResposta: ");
				scanf("%i", &opc);
				//std::cin >> opc;
				printLista(listaMenorP, listaMaiorP, opc);
				
				break;
				 
		}
    
    	do
		{
			printf("\n\nDeseja realizar nova operação? ");
			printf("\n(1) - SIM");
			printf("\n(2) - NÃO");
			printf("\nOPÇÃO: ");
			scanf("%i", &op);
			//std::cin >> op;
			
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
	return newListaMaiorP;
}

ListaMenorPrioridade* criarListaMenorPVazia()
{
	ListaMenorPrioridade *newListaMenorP = (ListaMenorPrioridade *)malloc(sizeof(ListaMenorPrioridade)); 
		
	newListaMenorP->inicio = NULL;
	newListaMenorP->fim = NULL;
	newListaMenorP->size = 0;
	return newListaMenorP;
}

Processos* criarNovoProcesso (std::string& nome, int id)
{
	Processos *newProcesso = (Processos *)malloc(sizeof(Processos));
	newProcesso->nome = &nome;
	newProcesso->PID = id;
	newProcesso->anterior = NULL;
	newProcesso->proximo = NULL;
	
	return newProcesso;
}

void adicionarProcesso(std::string& nome, int id, int opc, ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa)
{
	static int tmp = 0;
	static std::string nomeTemp[255];
	nomeTemp[tmp] = nome;
	//std::cout<<nome;
	Processos *newProcesso = criarNovoProcesso(nomeTemp[tmp], id);
	std::cout<<"\nNome: "<<*newProcesso->nome<<"\nPID: "<<newProcesso->PID<<"\n\n";
	
	tmp++;
	if (verificarListaVazia(listaMe, listaMa, opc) == true)
	{
		if (opc == 1)
		{	 
			listaMa->inicio = newProcesso;
			listaMa->fim = newProcesso;
			newProcesso->anterior = NULL;
			newProcesso->proximo = NULL;
		}
		else
		{
			listaMe->inicio = newProcesso;
			listaMe->fim = newProcesso;
			newProcesso->anterior = NULL;
			newProcesso->proximo = NULL;
		}
		
	}
	else
	{
		if (opc == 1)
		{
			listaMa->fim->proximo = newProcesso;
			listaMa->fim = newProcesso;
		}
		else
		{	
			listaMe->fim->proximo = newProcesso;
			listaMe->fim = newProcesso;
		}
	}	
}

std::string dadosProcesso(int *id, std::string& nome)
{	
	printf("\n\nNome: ");
	std::cin>>nome;
	printf("\nPID: ");
	scanf("%i", id);	
	//std::cin >> *id;
	//std::cout<<nome;
	return nome;		
}
bool verificarListaVazia(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	bool vazia = false;
	
	if (opc == 2 && listaMe->inicio == NULL)
	{ 	
		listaMe->inicio = NULL;
		listaMe->fim = NULL;
    	vazia = true;
	}		
	else if (opc == 1 && listaMa->inicio == NULL)
	{
		listaMa->inicio = NULL;
		listaMa->fim = NULL;
		vazia = true;
	}	
	return vazia;
}

void printProcesso(Processos *processo, int index)
{
	std::cout<<"\nNome: "<<*processo->nome<<"\nPID: "<<processo->PID<<"\n\n";
}


void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{

	if (verificarListaVazia(listaMe, listaMa, opc))
	{ 
		printf("\nLista Vazia");
	}
	else
	{	
		printf("\nMINHA LISTA DE CONTAS \n\n");

		if (opc == 1)
		{
			Processos *atual = listaMa->inicio; 
			int i = 0;
			while (atual != NULL)
			{ 		
				printProcesso(atual, i); 
				atual = atual->proximo;  
				i++;
			}
		}
		else
		{
			Processos *atual = listaMe->inicio; 
			int i = 0;
			while (atual != NULL)
			{ 		
				printProcesso(atual, i); 
				atual = atual->proximo;  
				i++;
			}
		}	
	}	
}
int obterTipoProcesso()
{
	int opc;
	
		do
		{
			printf("\n\nProcesso prioritário?\n1 - SIM\n2 - NÃO\nResposta: ");
			scanf("%i", &opc);
			//std::cin >> opc;
			if(opc < 1 || opc > 2)
			{
				printf("\n\nOpção Inválida! Digite novamente");
			}
		}while(opc < 1 || opc > 2);
		
	return opc;
}
