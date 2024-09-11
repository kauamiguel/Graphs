#include <stdio.h>
#include <stdlib.h>

int particiona(int *vetor, int inicio, int fim){
    int pivo  = vetor[(inicio  + fim) / 2];
    int aux = 0;

    while(inicio < fim){
        while(vetor[inicio] < pivo){
            inicio++;
        }

        while(vetor[fim] > pivo){
            fim--; 
        }
        
  
        aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        
    }

    return inicio;
}


void quickSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int posicao  = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, posicao - 1);
        quickSort(vetor, posicao + 1 , fim);
    }
}

int main(){
    int vetor[] = {45, 31, 21, 12, 42, 10, 49, 20, 33};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    quickSort(vetor, 0, tamanho - 1);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}