#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<stdlib.h>

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
void executarProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa);
void moverProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int id);
void finalizarProcesso(ListaMaiorPrioridade *lista);
void finalizarProcessoEspecifico(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int id);
void obterProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
void printProcesso(Processos *processo, int index);
void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
std::string dadosProcesso(int *id, std::string& nome);
bool verificarListaVazia(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
int obterTipoProcesso();
int printMenu(int op);

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
		
		
    	op = printMenu(op);
    	
    	switch (op)
		{
			case 1:
				 
				dadosProcesso(&id, nome);
				printf("\n\nProcesso de maior prioridade?\n\n1 - SIM\n2 - NÃO\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				//printf("%i", opc);
				//std::cout<<nome;
				adicionarProcesso(nome, id, opc, listaMenorP, listaMaiorP);
				system("cls");
				printLista(listaMenorP, listaMaiorP, opc);
				printf("\n\nAdicionado com sucesso!");
				
					
				break;
				
			case 2:
				
				executarProcesso(listaMenorP, listaMaiorP);
				system("cls");
				printf("Processo executado com sucesso!");
				
				break;
				
			case 6:
				
				printf("\n\nDeseja ver um processo:\n\n1 - Maior prioridade\n2 - Menor prioridade\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				system("cls");
				obterProcesso(listaMenorP, listaMaiorP, opc);
				
				break;
			
			case 7:
				
				printf("\n\nQual fila de processos deseja visualizar: \n\n1 - Maior prioridade\n2 - Menor prioridade\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				system("cls");
				//std::cin >> opc;
				printLista(listaMenorP, listaMaiorP, opc);
				
				break;
				
			default:
				
				printf("Opção inválida!!");
				 
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
				printf("\n\nOpção inválida! Digite novamente");
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
	
	Processos *newProcesso = criarNovoProcesso(nomeTemp[tmp], id);
	
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
void executarProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa)
{
	int opc = 1;
	
	if (verificarListaVazia(listaMe, listaMa, opc) == true)
	{ 
		opc = 2;
		
		if (verificarListaVazia(listaMe, listaMa, opc) == true)
		{
			printf("\nFilas Vazias!");
		}
		else
		{
			listaMe->fim->proximo = listaMe->inicio;
			listaMe->fim = listaMe->fim->proximo;	
			listaMe->inicio = listaMe->inicio->proximo;
			listaMe->fim->proximo = NULL;
		}	
	}
	else
	{
		opc = 2;
		
		Processos *temp;
		temp->proximo = listaMe->fim;
		*&temp->proximo = *&listaMa->inicio;
		listaMa->inicio = listaMa->inicio->proximo;
		
		if(verificarListaVazia(listaMe, listaMa, opc) == true)
		{
			listaMe->inicio = temp->proximo;
			listaMe->fim = temp->proximo;
			listaMe->inicio->proximo = listaMe->inicio;
			listaMe->fim->proximo = NULL;					
		}
		else
		{
			listaMe->fim->proximo = temp->proximo;
			listaMe->fim = temp->proximo;
			listaMe->fim->proximo = NULL;			
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
    	vazia = true;
	}		
	else if (opc == 1 && listaMa->inicio == NULL)
	{
		vazia = true;
	}	
	return vazia;
}

void printProcesso(Processos *processo, int index)
{
	printf("PROCESSO nº %i", index);
	std::cout<<"\nNome: "<<*processo->nome<<"\nPID: "<<processo->PID<<"\n\n";
}


void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{

	if (verificarListaVazia(listaMe, listaMa, opc))
	{ 
		printf("\nFila Vazia!");
	}
	else
	{	
		if (opc == 1)
		{
			printf("\nFILA DE PROCESSOS MAIOR PRIORIDADE \n\n");
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
			printf("\nFILA DE PROCESSOS MENOR PRIORIDADE \n\n");
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
			scanf("%i", &opc);
			//std::cin >> opc;
			if(opc < 1 || opc > 2)
			{
				printf("\n\nOpção Inválida! Digite novamente");
			}
		}while(opc < 1 || opc > 2);
		
	return opc;
}

void obterProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	if (verificarListaVazia(listaMe, listaMa, opc))
	{ 
		printf("\nFila Vazia!");
	}
	else
	{	
		int id;
		int i = 0;
		
		printf("Digite o PID do processo: ");
		scanf("%i", &id);
		system("cls");

		if (opc == 1)
		{
			Processos *atual = listaMa->inicio; 
			while (atual != NULL)
			{ 		 
				if(atual->PID == id)
				{
					printProcesso(atual, i); 
				}
				else if(id != atual->PID && atual->proximo == NULL)
				{
					printf("Índice inválido!!");
				
				}
				atual = atual->proximo; 
				i++;
			}
		}
	
		else
		{
			Processos *atual = listaMe->inicio; 
			while (atual != NULL)
			{ 		 
				if(atual->PID == id)
				{
					printProcesso(atual, i); 
				}
				else if(id != atual->PID && atual->proximo == NULL)
				{
					printf("Índice inválido!!");
				
				}
				atual = atual->proximo; 
				i++;
			}
		}	
	}	
}
int printMenu(int op)
{
		printf("ESCALONADOR DE PROCESSOS POR PRIORIDADE");
   	    printf("\n\nMenu:");
    	printf("\n\n(1) - Adicionar processo");
    	printf("\n(2) - Executar processo");
    	printf("\n(3) - Mover processo");
    	printf("\n(4) - Finalizar processo");
    	printf("\n(5) - Finalizar processo específico");
    	printf("\n(6) - Obter um processo");
    	printf("\n(7) - Imprimir fila\n\n");
    	printf("OPÇÃO: ");
    	scanf("%i",&op);
		//std::cin >> op;
		
		return op;
}

