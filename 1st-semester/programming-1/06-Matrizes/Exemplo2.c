#include <stdio.h>

#define LIN 3
#define COL 3

int main(){
    int i, j;
    float A[LIN][COL], B[LIN][COL], C[LIN][COL];

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Entre com os valores A[%d %d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("Entre com os valores B[%d %d]: ", i, j);
            scanf("%f", &B[i][j]);
        }}

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("znMatriz A\n");
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("[%.1f] ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B\n");
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("[%.1f] ", B[i][j]);
        }
        printf("\n");
        }

    printf("\nMatriz C, resultado da soma de A e B\n");
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            printf("[%.1f] ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}