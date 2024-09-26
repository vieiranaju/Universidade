#include <stdio.h>

void gravarArquivo(int n, int vetor[]) {
    char nomeArq[100];
    FILE *arq;

    printf("Digite o nome do arquivo");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "w");
    if (arq == NULL) {
        printf("Erro.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arq, "%d\n", vetor[i]);
    }

    fclose(arq);
}

int main() {
    int n;
    printf("Quantidade de valores: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite os %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    gravarArquivo(n, vetor);

    printf("Sucesso!\n");

    return 0;
}
