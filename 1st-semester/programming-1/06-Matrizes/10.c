#include <stdio.h>

int main(){
    int i, j, w = 0;
    int num[3][7], num2[3][7];

    for(i=0; i<3; i++){
        for(j=0; j<7; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

     for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            if (num[i][j] > 10 && num[i][j] < 50) {
                num2[i][j] = num[i][j];
                w++;
            } else {
                num2[i][j] = 0;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {

            printf("%d ", num2[i][j]);
        }
        printf("\n");
    }

   

    printf("%d elementos estavam entre 10 e 50", w);

    return 0;
}