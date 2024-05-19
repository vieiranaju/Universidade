#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main() {
    FILE *arq;
    int n[MAX];
    int soma = 0;

    printf("Digite %d números:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &n[i]);
    }

    arq = fopen("numeros.bin", "wb");
    if (arq == NULL) {
        printf("Erro.\n");
        return 1;
    }

    fwrite(n, sizeof(int), MAX, arq);

    fclose(arq);

    arq = fopen("numeros.bin", "rb");
    if (arq == NULL) {
        printf("Erro.\n");
        return 1;
    }

    for (int i = 0; i < MAX; i++) {
        int num;
        fread(&num, sizeof(int), 1, arq);
        soma += num;
    }

    fclose(arq);

    printf("A soma dos numeros é: %d\n", soma);

    return 0;
}
