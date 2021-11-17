#include<stdio.h>
#include<iostream>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

// 2010840 - Gabriele Cardoso das Virgens

/*  Aula 15 - 16/11/2021
	ESTRUTURA DE DADOS

    ****** FIBONACCI RECURSIVO ******
*/

long long int fibonacci (int termo);

int main (){

    setlocale(LC_ALL, "Portuguese"); 
    
    int termo;
    
    printf("#SEQUÊNCIA DE FIBONACCI#\n\n");
    printf("Digite quantos termos da sequência de fibonacci deseja imprimir:");
    scanf("%i", &termo);
    for(int i=0; i<termo; i++){
    	long long int r = fibonacci(i);
    	printf("\n%iº termo: %lld", i+1, r);	 
	}   
    return 0;
}

long long int fibonacci (int termo){
	
	long long int seq;
	
	if (termo == 1 || termo == 0){
		seq = 1;

		return seq;
	}
	else{
		seq = fibonacci(termo - 1) + fibonacci(termo - 2);

		return seq;			
	}
}