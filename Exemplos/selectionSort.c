#include <stdio.h>
#include <stdlib.h>

void selectionSort(int vetor[], int tamanho){
    int aux = 0 , menor;
      for(int i = 0; i < tamanho; i++){
        menor = i;

        for(int j = i + 1; j < tamanho; j++){
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
      }
}

int main(){
    int vetor[] = {45, 31, 21, 12, 42, 10, 49, 20, 33};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    selectionSort(vetor, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}