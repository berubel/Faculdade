#include <stdio.h>

int main(){
    
    int posicoes, chave, i;
    int vetor[8] = {1,2,3,4,5,6,7,8};

    printf("Digite a chave a ser procurada:");
    scanf("%i", &chave);

    for(i=0; i<8; i++){
        if(vetor[i] == chave){
            printf("Chave encontrada: %i", vetor[i]);
           break;
        }else if(i==7 && chave>vetor[i]){
            printf("A chave nao se encontra no conjunto de dados.");
        }
    }
}
