#include <stdio.h>
#include <stdlib.h>

void insertionSort(int vetor[], int tamanho){
    int aux = 0;
    for(int i = 1; i < tamanho; i++){
        for(int j = i; j > 0 && vetor[j] < vetor[j-1]; j--){
            aux = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor[j] = aux;
        }
    }
}

int main(){
    int vetor[] = {45, 31, 21, 12, 42, 10, 49, 20, 33};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}