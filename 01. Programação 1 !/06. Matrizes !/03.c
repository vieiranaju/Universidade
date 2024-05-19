#include <stdio.h>

int main(){
    int i, j, w = 0;
    int num[5][3];

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            if (num[i][j]%3 == 0)
            {
            w++;
            }
        }
    }

        int mult[w], p = 0;

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            if (num[i][j]%3 == 0)
            {
            mult[p] = num [i][j];
            p++;
            }
            
        }
    }

    for(j=0; j<w; j++){
            printf(" %d\n", mult[j]);
        }

    return 0;
}