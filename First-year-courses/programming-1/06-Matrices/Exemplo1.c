#include <stdio.h>

#define LIN 4
#define COL 4

int main(){
    int i, j;
    float notas[LIN][COL];

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Entre com as notas [%d %d]: ", i, j);
            scanf("%f", &notas[i][j]);
        }
    }

    for(j=0; j<COL; j++){
            printf("[%.1f] ", notas[0][j]);
        }
        printf("\n");
        
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("[%.1f] ", notas[i][j]);
        }
        printf("\n");
    }
    return 0;
}