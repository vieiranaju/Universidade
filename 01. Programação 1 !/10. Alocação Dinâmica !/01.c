// Implemente uma função que receba como parâmetro dois vetores vetX e vetY de tamanho n. 
// A função deve retornar o ponteiro para um vetor soma de tamanho n alocado dinamicamente, 
// em que soma = vetX + vetY
#include <stdio.h>
#include <stdlib.h>

int* soma(int* vetX, int* vetY, int n) {

    int* soma = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        soma[i] = vetX[i] + vetY[i];
    }
    
    return soma;
}

int main() {

    int n;

    printf("\nQual o tamanho do vetor?\n");
    scanf("%d", &n);

    int* vetX = (int*)malloc(n * sizeof(int));

    int* vetY = (int*)malloc(n * sizeof(int));

    if(vetX == NULL || vetY == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

    
    printf("\n Preencha o vetor X");

    for (int i = 0; i < n; i++) {

        printf("\nNumero [%d]:  ", i+1);
        scanf("%d", &vetX[i]);

    }

    
    printf("\n Preencha o vetor Y");

    for (int i = 0; i < n; i++) {

        printf("\nNumero [%d]:  ", i+1);
        scanf("%d", &vetY[i]);

    }

    
    int* resultado = soma(vetX, vetY, n);
    
    for (int i = 0; i < n; i++) {
        printf("\n%d ", resultado[i]);
    }
    
    free(resultado); 
    
    return 0;
}