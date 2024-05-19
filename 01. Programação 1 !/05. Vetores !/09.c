#include <stdio.h>

void arrumar(float vet[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
              
                float w = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = w;
            }
        }
    }
}

int main() {
    int n;
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    float vet[n];

    printf("Digite %i numeros! ", n );  
    for (int i = 0; i < n; i++) {
        scanf("%f", &vet[i]);
    }
  
    arrumar(vet, n);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", vet[i]);
    }

    return 0;
}