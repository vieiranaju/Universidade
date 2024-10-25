#include <stdio.h>

int main(){
    int i, j, w = 0;
    int num[5][5];

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if (i != j)
            {
                printf("%d ", num[i][j]);
            }
            else{
                printf("_ ");
                w = w + num[i][j];
            }
        }

         printf("\n");
    }

    printf("\nMedia = %d", w/5);

        

    return 0;
}