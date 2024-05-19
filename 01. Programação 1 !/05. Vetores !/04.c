#include <stdio.h>
#define TAM 21

int main() {
    int i = 0, vet[TAM - 1], count = 0;

    printf("Insira %d numeros:\n", TAM);

    for (i = 0; i < TAM; i++) {
        scanf("%d", &vet[i]);
    }

    int z = vet[TAM-1]; 
    for (i = 0; i < TAM; i++) {
        if (vet[i] == z) {
            count++;
        }
    }

    int vet2[count], a = 0;

    for (i = 0; i < TAM; i++) {
        if (vet[i] == z) {
            vet2[a] = i + 1;
            a++;
        }
    }

    printf("\n %d apareceu %d vezes!!, nas posições ", z, a);
    for (i = 0; i < a; i++) {
        printf("%d ", vet2[i]);
    }

    return 0;
}
