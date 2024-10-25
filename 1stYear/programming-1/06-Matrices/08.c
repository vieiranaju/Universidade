#include <stdio.h>

int soma(int w, int num[w][w]){

    int i, j, soma = 0;

    for(i=0; i<w; i++){
        for(j=0; j<w; j++){

            if (i + j != w - 1 && i != j)
            {
            soma = soma + num[i][j];
            }
        }
    }

    return soma;

}

int main(){
    int i, j, w;

     printf("Escolha as dimensões para a matriz quadrada:\n");
        scanf("%d", &w);

    int num[w][w];

    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    printf("%d", soma(w, num));

    return 0;
}