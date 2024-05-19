#include <stdio.h>

void gravarMatriz( int x, int y, int matriz[x][y]) {
    FILE *arq;
    char nomeArq[100];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "w");

    if (arq == NULL) {
        printf("Erro.\n");
        return;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            fprintf(arq, "%d ", matriz[i][j]);
        }
        fprintf(arq, "\n");
    }

    fclose(arq);
    printf("Sucesso!\n");
}

int main() {
    int lin, col;

    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    int matriz[lin][col];

    printf("Digite os valores:\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    gravarMatriz(lin, col, matriz);

    return 0;
}
