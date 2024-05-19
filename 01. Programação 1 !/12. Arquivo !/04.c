#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeArq1[100], nomeArq2[100], nomeArq3[100];
    FILE *arq1, *arq2, *arq3;
    char c;

    printf("Digite o nome do arquivo 1: ");
    scanf("%s", nomeArq1);
    printf("Digite o nome do arquivo 3: ");
    scanf("%s", nomeArq2);
    printf("Digite o nome do arquivo 3 ");
    scanf("%s", nomeArq3);

    arq1 = fopen(nomeArq1, "r");
    if (arq1 == NULL) {
        printf("Erro.\n");
        return 1;
    }

    arq2 = fopen(nomeArq2, "r");
    if (arq2 == NULL) {
        printf("Erro.\n");
        fclose(arq1);
        return 1;
    }

    arq3 = fopen(nomeArq3, "a");
    if (arq3 == NULL) {
        printf("Erro.\n");
        fclose(arq1);
        fclose(arq2);
        return 1;
    }

    while ((c = fgetc(arq1)) != EOF) {
        fputc(c, arq3);
    }

    while ((c = fgetc(arq2)) != EOF) {
        fputc(c, arq3);
    }

    printf("Arquivos %s e %s foram armazenados em %s.\n", nomeArq1, nomeArq2, nomeArq3);

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    return 0;
}
