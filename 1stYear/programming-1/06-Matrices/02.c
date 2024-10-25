#include <stdio.h>

int main(){
    int i, j;
    float num[3][5], soma[5];

    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%f", &num[i][j]);
        }
    }
    for(i=0; i<5; i++){
        soma[i] = 0;

        for(j=0; j<3; j++){
            soma[i] = soma[i] + num[j][i];
        }
    }
    for(j=0; j<5; j++){
            printf("Soma %d: %.2f\n", j, soma[j]);
        }

    return 0;
}