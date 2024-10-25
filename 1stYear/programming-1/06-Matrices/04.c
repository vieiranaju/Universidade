#include <stdio.h>

int min(int num[4][5]){

    int i, j, menor;
    menor = num[0][0];

    for(i=0; i<4; i++){
        for(j=0; j<5; j++){

            if (num[i][j] < menor)
            {
            menor = num[i][j];
            }
        }
    }

    return menor;

}

int main(){
    int i, j;
    int num[4][5];

    for(i=0; i<4; i++){
        for(j=0; j<5; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    printf("menor = %d", min(num));
    return 0;
}