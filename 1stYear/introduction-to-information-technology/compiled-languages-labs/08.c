#include <stdio.h>

int main() {
    int x = 1, y = 2, z = 0, soma = 0;

    while (z <= 4000000) {
        // o programa é encerrado quando o valor de z for maior ou igual a 4000000
        z = x + y; 
        // z armazena a soma de x e y
        x = y; 
        // x passa a armazenar o valor de y
        y = z; 
        // y passa a armazenar o valor de z
        
        if (z % 2 == 0) {
            soma = soma + z; 
            // se a divisão de z por 2 tiver resto 0, ele é par, então é somado a variável soma
        }

        printf("\n%i", z); 
        // mostra o valor de z
    }

    printf("\nA soma dos termos pares é %i", soma); 
    // mostra o resultado da soma

    return 0;
}
