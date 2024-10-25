#include <stdio.h>

int main() {
    int x, i = 1;
    scanf("%d", &x);
    
    while (i <= 10) {
        // realiza a multiplicação de 1 a 10 do número escolhido
        printf("\n%i x %i = %i", x, i, x * i);
        i++;
    }

    return 0;
}
