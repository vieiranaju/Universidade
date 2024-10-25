#include <stdio.h>

int maior(int *pos, int *large, int x) {
    int position = 0;

    for(int i = 0; i < x; ++i) {
        if(pos[i] > *large) {
            *large = pos[i];
            position = i;
        }
    }

    return position;
}

int main() {
    int x, large = 0;
    printf("Escolha o tamanho para o vetor:\n");
    scanf("%d", &x);
    int num[x];

    printf("Preencha os valores do vetor:\n");
    for (int i = 0; i < x; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &num[i]);
    }

    int position = maior(num, &large, x);

    printf("O maior elemento aparece eh %d e esta na posicao %d!", large, position + 1);

    return 0;
}
