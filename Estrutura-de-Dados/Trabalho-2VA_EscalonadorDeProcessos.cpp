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
	struct Processos *proximo;
};

typedef struct ListaMaiorPrioridade
{
	struct Processos *inicio;
	struct Processos *fim;
};

typedef struct ListaMenorPrioridade
{
	struct Processos *inicio;
	struct Processos *fim;
};

Processos* criarNovoProcesso (std::string& nome, int id);
ListaMaiorPrioridade* criarListaMaiorPVazia();
ListaMenorPrioridade* criarListaMenorPVazia();
void adicionarProcesso(std::string& nome, int id, int opc, ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa);
void executarProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa);
void moverProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
void finalizarProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa);
void finalizarProcessoEspecifico(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
int obterProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
void printProcesso(Processos *processo, int index);
void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
std::string dadosProcesso(int *id, std::string& nome);
bool verificarListaVazia(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc);
int obterTipoProcesso();

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
    	printf("\n(7) - Imprimir fila\n\n");
    	printf("OPÇÃO: ");
    	scanf("%i",&op);
    	
    	switch (op)
		{
			case 1:
				 
				dadosProcesso(&id, nome);
				printf("\n\nProcesso de maior prioridade?\n\n1 - SIM\n2 - NÃO\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				adicionarProcesso(nome, id, opc, listaMenorP, listaMaiorP);
				system("cls");
				printLista(listaMenorP, listaMaiorP, opc);
				printf("\n\nAdicionado com sucesso!");
					
				break;
				
			case 2:
				
				executarProcesso(listaMenorP, listaMaiorP);
				system("cls");
				opc = 1;
				printLista(listaMenorP, listaMaiorP, opc);
				opc = 2;
				printLista(listaMenorP, listaMaiorP, opc);
				printf("\nProcesso executado com sucesso!");
				
				break;
				
			case 3:
				
				printf("\n\nDeseja mover um processo da fila: \n\n1 - Maior Prioridade \n2 - Menor Prioridade\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				system("cls");
				moverProcesso(listaMenorP, listaMaiorP, opc);
				
				break;
				
			case 4:
				
				printf("\n\nO processo de maior prioridade será encerrado. Tem certeza que seja realizar a operação: \n\n1 - SIM \n2 - NÃO\n\nOPÇÃO:  ");
				scanf("%i", &opc);
				system("cls");
				if (opc == 1)
				{
					finalizarProcesso(listaMenorP, listaMaiorP);
				}
				
				break;
				
			case 5:
				
				printf("\n\nDeseja finalizar um processo da fila: \n\n1 - Maior Prioridade \n2 - Menor Prioridade\n\nOPÇÃO: ");
				opc = obterTipoProcesso();
				printf("\n\nO processo escolhido será encerrado. Tem certeza que seja realizar a operação: \n\n1 - SIM \n2 - NÃO\n\nOPÇÃO:  ");
				scanf("%i", &op);
				system("cls");
				if (op == 1)
				{
					finalizarProcessoEspecifico(listaMenorP, listaMaiorP, opc);
				}
				
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
			
			if (op < 1|| op > 2)
			{
				printf("\n\nOpção inválida! Digite novamente");
			}	
				
		}while(op < 1 || op > 2);
		
		system("cls");
	
	} while (op == 1);
      
    return 0;
}

Processos* criarNovoProcesso (std::string& nome, int id)
{
	Processos *newProcesso = (Processos *)malloc(sizeof(Processos));
	newProcesso->nome = &nome;
	newProcesso->PID = id;
	newProcesso->proximo = NULL;
	
	return newProcesso;
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
			newProcesso->proximo = NULL;	
		}
		else
		{
			listaMe->inicio = newProcesso;
			listaMe->fim = newProcesso;
			newProcesso->proximo = NULL;
		}		
	}
	else
	{
		if (opc == 1)
		{ 
			listaMa->fim->proximo = newProcesso;
			listaMa->fim = newProcesso;
			listaMa->fim->proximo = NULL;	
		}
		else
		{
			listaMe->fim->proximo = newProcesso;
			listaMe->fim = newProcesso;
			listaMe->fim->proximo = NULL;
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
		temp = listaMe->fim;
		*&temp = *&listaMa->inicio;
		listaMa->inicio = listaMa->inicio->proximo;
		
		if(verificarListaVazia(listaMe, listaMa, opc) == true)
		{
			listaMe->inicio = temp;
			listaMe->fim = temp;
			listaMe->inicio->proximo = listaMe->inicio;
			listaMe->fim->proximo = NULL;					
		}
		else
		{
			listaMe->fim->proximo = temp;
			listaMe->fim = temp;
			listaMe->fim->proximo = NULL;			
		}		
	}	
}

void moverProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	Processos *atual;
	Processos *anterior;
	
	if (verificarListaVazia(listaMe, listaMa, opc) == false)
	{
		printLista(listaMe, listaMa, opc);
		int id = obterProcesso(listaMe, listaMa, opc);
		system("cls");
		
		if (opc == 1)
		{
			opc = 2;
		
			atual = listaMa->inicio; 
			anterior = listaMa->inicio;
	
			int i = 0;
				
			while(atual != NULL && i !=id)
			{
				anterior = atual;		
        			atual = atual->proximo;
        			i++;
			}
			if((i>=id || i!=id) && atual == NULL)
			{
				printf("Índice inválido!!");
			}			
			else if (i == id)
			{
				if(id == 0)
				{
					listaMa->inicio = listaMa->inicio->proximo;				
				}
				else if(atual->proximo == NULL)
				{	
					listaMa->fim = anterior;
					listaMa->fim->proximo = NULL;
				}
				else
				{
					anterior->proximo = atual->proximo;
				}
				printLista(listaMe, listaMa, 1);
				
				if (verificarListaVazia(listaMe, listaMa, opc) == true)
				{
					listaMe->inicio = atual;	
					listaMe->fim = atual;
					listaMe->fim->proximo = atual;
					listaMe->inicio->proximo = listaMe->inicio;
					listaMe->fim->proximo = NULL;	
					printLista(listaMe, listaMa, opc);
					printf("\n\nProcesso movido com sucesso para fila de menor prioridade.");
				}
				else
				{
					listaMe->fim->proximo = atual;
					listaMe->fim = atual;
					listaMe->fim->proximo = NULL;
					printLista(listaMe, listaMa, opc);
					printf("\n\nProcesso movido com sucesso para fila de menor prioridade.");
				}	
			}	
		}
		else
		{
			opc = 1;
		
			atual = listaMe->inicio; 
			anterior = listaMe->inicio;
	
			int i = 0;
			
			while(atual != NULL && i !=id)
			{		
				anterior = atual;		
        			atual = atual->proximo;
        			i++;
			}
			if((i>=id || i!=id) && atual == NULL)
			{
				printf("Índice inválido!!");
			}	
			else if(i == id)
			{
				if(id == 0)
				{
					listaMe->inicio = listaMe->inicio->proximo;
				}
				else if(atual->proximo == NULL)
				{
					listaMe->fim = anterior;
					listaMe->fim->proximo = NULL;
				}
				else
				{
					anterior->proximo = atual->proximo;
				}
				printLista(listaMe, listaMa, 2);
						
				if (verificarListaVazia(listaMe, listaMa, opc) == true)
				{
					listaMa->inicio = atual;	
					listaMa->fim = atual;
					listaMa->fim->proximo = atual;
					listaMa->inicio->proximo = listaMa->inicio;
					listaMa->fim->proximo = NULL;
					printLista(listaMe, listaMa, opc);
					printf("\n\nProcesso movido com sucesso para fila de maior prioridade.");	
				}
				else
				{
					listaMa->fim->proximo = atual;
					listaMa->fim = atual;
					listaMa->fim->proximo = NULL;
					printLista(listaMe, listaMa, opc);
					printf("\n\nProcesso movido com sucesso para fila de maior prioridade.");
				}
			}
		}
	}	
	else
	{
		if (opc == 1)
		{
			printf("\nFila maior prioridade vazia!");
		}
		else
		{
			printf("\nFila menor prioridade vazia!");
		}
	}	
}

void finalizarProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa)
{
	int opc = 1;
	
	if(verificarListaVazia(listaMe, listaMa, opc) == false)
	{
		printLista(listaMe, listaMa, opc);
		listaMa->inicio = listaMa->inicio->proximo;
		printLista(listaMe, listaMa, opc);
		printf("\n\nProcesso finalizado com sucesso!");
	}
	else 
	{
		opc = 2;
		
		if (verificarListaVazia(listaMe, listaMa, opc) == false)
		{
			printLista(listaMe, listaMa, opc);
			listaMe->inicio = listaMe->inicio->proximo;
			printLista(listaMe, listaMa, opc);
			printf("\n\nProcesso finalizado com sucesso!");
		}
		else
		{
			printf("\nFilas vazias!");	
		}
	}
}

void finalizarProcessoEspecifico(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	Processos *atual;
	Processos *anterior;
	
	if (verificarListaVazia(listaMe, listaMa, opc) == false)
	{
		printLista(listaMe, listaMa, opc);
		int id = obterProcesso(listaMe, listaMa, opc);
		system("cls");
		
		if (opc == 1)
		{
			opc = 2;
		
			atual = listaMa->inicio; 
			anterior = listaMa->inicio;
	
			int i = 0;
				
			while(atual != NULL && i !=id)
			{
				anterior = atual;		
        			atual = atual->proximo;
        			i++;
			}
			if((i>=id || i!=id) && atual == NULL)
			{
				printf("Índice inválido!!");
			}			
			else if (i == id)
			{
				if(id == 0)
				{
					listaMa->inicio = listaMa->inicio->proximo;				
				}
				else if(atual->proximo == NULL)
				{	
					listaMa->fim = anterior;
					listaMa->fim->proximo = NULL;
				}
				else
				{
					anterior->proximo = atual->proximo;
				}
				printLista(listaMe, listaMa, 1);
			}	
		}
		else
		{
			opc = 1;
		
			atual = listaMe->inicio; 
			anterior = listaMe->inicio;
	
			int i = 0;
			
			while(atual != NULL && i !=id)
			{		
				anterior = atual;		
        			atual = atual->proximo;
        			i++;
			}
			if((i>=id || i!=id) && atual == NULL)
			{
				printf("Índice inválido!!");
			}	
			else if(i == id)
			{
				if(id == 0)
				{
					listaMe->inicio = listaMe->inicio->proximo;
				}
				else if(atual->proximo == NULL)
				{
					listaMe->fim = anterior;
					listaMe->fim->proximo = NULL;
				}
				else
				{
					anterior->proximo = atual->proximo;
				}
				printLista(listaMe, listaMa, 2);
			}
		}
	}	
	else
	{
		if (opc == 1)
		{
			printf("\nFila maior prioridade vazia!");
		}
		else
		{
			printf("\nFila menor prioridade vazia!");
		}
	}	
}

int obterProcesso(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	if (verificarListaVazia(listaMe, listaMa, opc) == true)
	{ 
		if (opc == 1)
		{
			printf("\nFila maior prioridade vazia!");
		}
		else
		{
			printf("\nFila menor prioridade vazia!");
		}
	}
	else
	{	
		int id;
		int i = 0;
		
		printf("Digite o índice (nº da posição na fila) do processo: ");
		scanf("%i", &id);
		Processos *atual;
		
		if (opc == 1)
		{
			atual = listaMa->inicio;
			
			while (atual != NULL)
			{ 		 
				if(i == id)
				{
					printf("PROCESSO MAIOR PRIORIDADE \n\n");
					printProcesso(atual, i); 
				}
				else if(id != i && atual == NULL)
				{
					printf("Índice inválido!!");
				
				}
				atual = atual->proximo; 
				i++;
			}
		}
		else
		{
			atual = listaMe->inicio;
				
			while (atual != NULL)
			{ 		 
				if(i == id)
				{
					printf("PROCESSO MENOR PRIORIDADE \n\n");
					printProcesso(atual, i); 
				}
				else if(id != i && atual == NULL)
				{
					printf("Índice inválido!!");
				
				}
				atual = atual->proximo; 
				i++;
			}
		}
		return id;	
	}	
}

void printProcesso(Processos *processo, int index)
{
	printf("PROCESSO nº %i", index);
	std::cout<<"\nNome: "<<*processo->nome<<"\nPID: "<<processo->PID<<"\n\n";
}

void printLista(ListaMenorPrioridade *listaMe, ListaMaiorPrioridade *listaMa, int opc)
{
	if (verificarListaVazia(listaMe, listaMa, opc) == true)
	{ 
		if (opc == 1)
		{
			printf("\nFila maior prioridade vazia!\n");
		}
		else
		{
			printf("\nFila menor prioridade vazia!\n");
		}
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

std::string dadosProcesso(int *id, std::string &nome)
{	
	printf("\n\nNome: ");
	std::cin>>nome;
	printf("\nPID: ");
	scanf("%i", id);	
	
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

int obterTipoProcesso()
{
	int opc;
	
		do
		{
			scanf("%i", &opc);
			
			if(opc < 1 || opc > 2)
			{
				printf("\n\nOpção Inválida! Digite novamente");
			}
		}while(opc < 1 || opc > 2);
		
	return opc;
}


