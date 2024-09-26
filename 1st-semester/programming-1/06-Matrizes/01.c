#include <stdio.h>

int main(){
    int i, j;
    float num[5][3], soma;

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%f", &num[i][j]);
        }
    }
    for(i=0; i<5; i++){
        soma = 0;

        for(j=0; j<3; j++){
            soma = soma + num[i][j];
        }

        printf("\nLinha %d: %.1f", i, soma);
    }

    return 0;
}