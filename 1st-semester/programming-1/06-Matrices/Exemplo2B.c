#include <stdio.h>

#define MAX 5

void soma(float vet[MAX][MAX], float vet2[MAX][MAX], float result[MAX][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            result[i][j] = vet[i][j] + vet2[i][j];
        }
    }
}

int main() {
    int i, j;
    float A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("Entre com o valor de A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("Entre com o valor de B[%d][%d]: ", i, j);
            scanf("%f", &B[i][j]);
        }
    }

    printf("\nMatriz A\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("[%.1f] ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("[%.1f] ", B[i][j]);
        }
        printf("\n");
    }

    soma(A, B, C);

    printf("\nMatriz C, resultado da soma de A e B\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("[%.1f] ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
