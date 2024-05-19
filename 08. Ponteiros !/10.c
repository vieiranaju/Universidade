#include <stdio.h>
#define w 4

void constante(int p[w][w], int x, int *total) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            if (p[i][j] == x) {
                (*total)++;
            }
        }
    }
}

int main() {
    int i, j, x, num[w][w], total = 0;

    printf("Escolha a constante x:\n");
    scanf("%d", &x);

    printf("Preencha os valores da matriz:\n");

    for (i = 0; i < w; i++) {
        for (j = 0; j < w; j++) {
            printf("Numero [%d %d]: ", i, j);
            scanf("%d", &num[i][j]);
        }
    }

    constante(num, x, &total);

    printf("%d aparece %d vezes ! ", x, total);

    return 0;
}
