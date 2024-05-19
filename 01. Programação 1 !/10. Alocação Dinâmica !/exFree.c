#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array, i;

    array = (int *) malloc(20 * sizeof(int));

    if(array == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

    for(i = 0; i < 20; ++i){
        array[i] = i;
    }

    for(i = 0; i < 20; ++i){
        printf("%d ", array[i]);
    }

    // Libera memoria alocada
    free(array);

    return 0;

}