#include <stdio.h>

int main() {
    int i, x, menor = 999999, maior = 0;

    for (i = 0; i <= 15; i++) {
        // estrutura para receber os 15 numeros
        scanf("%d", &x);
        
        if (x >= 0) {
            // verifica se é positivo
            if (menor > x) {
                menor = x; 
                // verificar se o valor é menor e então armazenar caso seja
            } else if (maior < x) {
                maior = x; 
                // verificar se o valor é maior e então armazenar caso seja
            }
        } else {
            break; 
            // caso o valor inserido seja negativo o programa para
        }
    }

    printf("O menor valor foi %d e o maior %d", menor, maior);
    // mostra os valores

    return 0;
}
