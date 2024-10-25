#include <stdio.h>

int mult(int num, int x){

    int mult;

        mult = x * num;

    return mult;

}

int main(){
    int i, j, w, x;


    printf("Escolha as dimensões para a matriz quadrada:\n");
        scanf("%d", &w);

    printf("Escolha a constante x:\n");
        scanf("%d", &x);

    int num[w][w];

    printf("Preencha os valores da matriz:\n");

    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            if (i + j == w - 1){

                num[i][j] = mult(x, num[i][j]);

            }

        }}

    for(i=0; i<w; i++){
        for(j=0; j<w; j++){

        printf("%d ", num [i][j]);
        }

    printf("\n");
    }    
    
    return 0;
}