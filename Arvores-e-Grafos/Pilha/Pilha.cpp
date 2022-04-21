#include<iostream>
#include <stdio.h>
#include<locale.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5
using namespace std;

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 5 - 16/03/2022
	ESTRUTURA DE DADOS II
	ÁRVORE E GRAFOS

    ****** IMPLEMENTAÇÃO DE PILHA SIMPLES ******
*/

//define a estrutura que será a pilha
//a estrutura armazena a indicação do inicio e final da pilha e um vetor com os itens (valores) da pilha
typedef struct{
    int ini = 0;
    int fin = 0;
    char iten [SIZE] ;
}STACK;

//Protótipo das funções
bool emptyStack(STACK p);
bool fullStack(STACK p);
void stackUp(STACK &p, char x);
void unstack(STACK &p);
void printStack(STACK p);
void getElement(STACK p, int n);

//Variavel global contadora
int cont=0;

//Função principal
int main(){
	
	setlocale(LC_ALL, "Portuguese"); 
	
	STACK s; //criar a pilha
	int op;
	
	 do {
    	printf("PILHA");
   	 	printf("\n\nMenu:");
    	printf("\n\n(1) - Inserir novo elemento no final da pilha");
    	printf("\n(2) - Remover elemento do final da pilha");
    	printf("\n(3) - Obter um elemento da pilha");
    	printf("\n(4) - Imprimir pilha");
    	printf("\n(5) - Sair do programa\n\n");
    	printf("OPÇÃO: ");
    	cin >> op;
    
    	switch(op){
		
			case 1: //INSERIR ELEMENTO NO FINAL	
				char c;
				
				if(fullStack(s)) {
			        cout <<"\nA pilha esta cheia. Impossível inserir elemento!"<<endl;
			    } else {
			       	cout <<"\nInsira um elemento (caractere) na pilha: "<<endl;
					cin >> c;
					stackUp(s, c);
					system("cls");
					cout<<"\nAdicionado com sucesso!"<<endl;
			    }	
			break;
			
			
			case 2: //REMOVER ELEMENTO DO INÍCIO
				 if(emptyStack(s)) {
			        cout <<"\nA pilha esta vazia. Impossível remover elemento!"<<endl;
			    } else {
			        cout <<"\nValor removido da fila: ";
			        unstack(s);
			    }	  				
			break;
			
			case 3:  //OBTER UM ELEMENTO		
				int position;
				
				cout <<"\nDigite o número da posição da conta que deseja visualizar: "<<endl;
			    cin >> position;
				getElement(s, position);					
			break;
			
			case 4: //IMPRIMIR FILA  
			   	system("cls");
				printStack(s);		
			break;
		
			case 5:	
				return 0;			
			break;
			
			default: 		
				cout<<"\nOpção inválida!"<<endl;			
		}		
		do{
			cout<<"\n\nDeseja realizar nova operação? "<<endl;
			cout<<"\n(1) - SIM"<<endl;
			cout<<"\n(2) - NÃO"<<endl;
			cout<<"\nOPÇÃO: "<<endl;
			cin >> op;
			
			if (op < 1|| op > 2){
				cout <<"\n\nOpção inválida!"<<endl;
			}	
		}while(op < 1|| op > 2);
		
		if (op == 1){
			system("cls");
		}	
	} while (op == 1);
    
    return 0;
}

//retorna se a pilha está vazia ou não
bool emptyStack(STACK p){
    if(p.ini == p.fin) {
        return true;
    } else {
        return false;
    }
}

//retorna se a pilha está cheia ou não
bool fullStack(STACK p){
	int size = sizeof(p.iten)/sizeof(char); //determina o tamanho do vetor
	
    if (p.fin < size) {
        return false;
    } else {
        return true;
    }
}

//adiciona valor na pilha
void stackUp(STACK &p, char x){
    p.iten[p.fin++] = x;
    cont++;
}

//remove valor da pilha
void unstack(STACK &p){
	cout << p.iten[p.fin-1];
	p.iten[p.fin--];
	cont--;
}

//mostra os valores armazenados na pilha
void printStack(STACK p){
	if(emptyStack(p)) {
		cout <<"\nA pilha está vazia"<<endl;
	} else {
		cout << "Valores da fila: \n";
		for (int i = p.ini; i < p.fin; i++) {
			cout << i << "º = "<< p.iten[i];
			cout << "\n";
		}
	}
}

//obtém um elemento da pilha
void getElement(STACK p, int n) {
	if(emptyStack(p)) {
		cout <<"\nA pilha esta vazia. Impossível obter elemento!"<<endl;
	} else {
			for (int i = 0; i < cont; i++) {
			if(i == n){
				cout <<"\n"<< i << "º = "<< p.iten[i];
			}
		}
		if(n < 0 || n >= cont){
				cout << "\nPosição informada fora dos limites da pilha!";
		}
	}
}




