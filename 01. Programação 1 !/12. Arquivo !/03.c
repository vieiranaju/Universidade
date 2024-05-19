#include <stdio.h>

#define MAX 20

int main() {
    int A[MAX];
    FILE *arquivo;

    printf("Digite 20 valores inteiros:\n");
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &A[i]);
    }

    arquivo = fopen("valores.txt", "w");
    if (arquivo == NULL) {
        printf("Erro.\n");
        return 1;
    }

    for (int i = 0; i < MAX; i++) {
        fprintf(arquivo, "%d\n", A[i]);
    }

    fclose(arquivo);

    // Ler os valores do arquivo e armazenar em B
    int B[MAX];
    arquivo = fopen("valores.txt", "r");
    if (arquivo == NULL) {
        printf("Erro\n");
        return 1;
    }

    for (int i = 0; i < MAX; i++) {
        if (fscanf(arquivo, "%d", &B[i]) != 1) {
            printf("Erro ao ler arquivo.\n");
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);

    printf("Valores:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\n", B[i]);
    }

    return 0;
}
