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
	�RVORE E GRAFOS

    ****** IMPLEMENTA��O DE FILA SIMPLES ******
*/

//define a estrutura que ser� a fila
//a estrutura armazena a indica��o do inicio e final da fila e um vetor com os itens (valores) da fila
typedef struct{
    int ini = 0;
    int fin = 0;
    char iten [SIZE] ;
}QUEUE;

//Prot�tipo das fun��es
bool emptyQueue(QUEUE p);
bool fullQueue(QUEUE p);
void toQueue(QUEUE &p, char x);
void dequeue(QUEUE &p);
void printQueue(QUEUE p);
void getElement(QUEUE p, int n);

//Variavel global contadora
int cont=0;

//Fun��o principal
int main(){
	
	setlocale(LC_ALL, "Portuguese"); 
	
	QUEUE s; //criar a fila
	int op;
	
	 do {
    	printf("FILA");
   	 	printf("\n\nMenu:");
    	printf("\n\n(1) - Inserir novo elemento no final da fila");
    	printf("\n(2) - Remover elemento do in�cio da fila");
    	printf("\n(3) - Obter um elemento da fila");
    	printf("\n(4) - Imprimir fila");
    	printf("\n(5) - Sair do programa\n\n");
    	printf("OP��O: ");
    	cin >> op;
    
    	switch(op){
		
			case 1: //INSERIR ELEMENTO NO FINAL	
				char c;
				
				if(fullQueue(s)) {
			        cout <<"\nA fila esta cheia. Imposs�vel inserir elemento!"<<endl;
			    } else {
			       	cout <<"\nInsira um elemento (caractere) na fila: "<<endl;
					cin >> c;
					toQueue(s, c);
					system("cls");
					cout<<"\nAdicionado com sucesso!"<<endl;
			    }	
			break;
			
			
			case 2: //REMOVER ELEMENTO DO IN�CIO
				 if(emptyQueue(s)) {
			        cout <<"\nA fila esta vazia. Imposs�vel remover elemento!"<<endl;
			    } else {
			        cout <<"\nValor removido da fila: ";
			        dequeue(s);
			    }	  				
			break;
			
			case 3:  //OBTER UM ELEMENTO		
				int position;
				
				cout <<"\nDigite o n�mero da posi��o do elemento que deseja visualizar: "<<endl;
			    cin >> position;
				getElement(s, position);					
			break;
			
			case 4: //IMPRIMIR FILA  
			   	system("cls");
				printQueue(s);		
			break;
		
			case 5:	
				return 0;			
			break;
			
			default: 		
				cout<<"\nOp��o inv�lida!"<<endl;			
		}		
		do{
			cout<<"\n\nDeseja realizar nova opera��o? "<<endl;
			cout<<"\n(1) - SIM"<<endl;
			cout<<"\n(2) - N�O"<<endl;
			cout<<"\nOP��O: "<<endl;
			cin >> op;
			
			if (op < 1|| op > 2){
				cout <<"\n\nOp��o inv�lida!"<<endl;
			}	
		}while(op < 1|| op > 2);
		
		if (op == 1){
			system("cls");
		}	
	} while (op == 1);
    
    return 0;
}

//retorna se a fila est� vazia ou n�o
bool emptyQueue(QUEUE p){
    if(p.ini == p.fin) {
        return true;
    } else {
        return false;
    }
}

//retorna se a fila est� cheia ou n�o
bool fullQueue(QUEUE p) {
	int size = sizeof(p.iten)/sizeof(char); //determina o tamanho do vetor
	
    if (p.fin < size) {
        return false;
    } else {
        return true;
    }
}

//adiciona valor na fila
void toQueue(QUEUE &p, char x){
    p.iten[p.fin++] = x;
    cont++;
}

//remove valor da fila
void dequeue(QUEUE &p){
	cout << p.iten[p.ini];
	p.iten[p.ini++];
	cont--;
}

//mostra os valores armazenados na fila
void printQueue(QUEUE p) {
	if(emptyQueue(p)) {
		cout <<"\nA fila est� vazia"<<endl;
	} else {
		cout << "Valores da fila: \n";
		for (int i = p.ini; i < p.fin; i++) {
			cout << i << "� = "<< p.iten[i];
			cout << "\n";
		}
	}
}

//obt�m um elemento da fila
void getElement(QUEUE p, int n) {
	if(emptyQueue(p)) {
		cout <<"\nA fila esta vazia. Imposs�vel obter elemento!"<<endl;
	} else {
		for (int i = 0; i < cont; i++) {
			if(i == n){
				cout <<"\n"<< i << "� = "<< p.iten[i];
			}
		}
		if(n < 0 || n >= cont){
				cout << "\nPosi��o informada fora dos limites da fila!";
		}
	}
}


