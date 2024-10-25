#include <stdio.h>

int main() {
    int i, y, soma = 0;

    scanf("%d", &y);
    
    for (i = 1; i <= y; i++) {
        // verificar todos os números de 1 a y
        if (i % 3 == 0 || i % 5 == 0) {
            // verifica se o número é múltiplo de 3 ou 5
            printf("%d\n", i);
            // mostra esse número e realiza a soma dele com o número armazenado
            soma = soma + i;
        }
    }

    // Opcional: imprimir a soma total dos múltiplos
    printf("A soma dos múltiplos de 3 e 5 até %d é: %d\n", y, soma);

    return 0;
}
