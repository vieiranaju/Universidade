#include <stdio.h>

void percorre(int *ptr_inicio, int x) {

    int *ptr_fim = ptr_inicio + x - 1;

    while(ptr_inicio < ptr_fim) {
        printf ("%d ", *ptr_inicio);
        printf ("%d ", *ptr_fim);
        ptr_inicio++;
        ptr_fim--;
    }
    printf("\n");
}


int main() {
    int x;

    printf("Escolha o tamanho para o vetor:\n");
    scanf("%d", &x);

    int num[x];

    printf("Preencha os valores do vetor:\n");
    for (int i = 0; i < x; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &num[i]);
    }

    percorre(num, x);

    return 0;
}
