#include <stdio.h>

int main(){
    int i, j, x, y;

    printf("Insira a quantia de linhas da mariz: \n");
        scanf("%d", &x);
    printf("\nInsira a quantia de colunas da mariz: \n");
        scanf("%d", &y);


    int num[x][y], num1[y][x];

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }
    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            num1[j][i] = num [i][j];
        }  
    }

    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            printf("%d ", num1[i][j]);
        }
        printf("\n");
    }


    return 0;
}