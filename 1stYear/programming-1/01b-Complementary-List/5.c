#include <stdio.h>
#include <math.h>

int main(){

        int a, b, c, d;

    printf("Insira 4 valores inteiros para calcular a diferenca do produto de A e B pelo produto de C e D.");
    scanf("%f%f%f%f", &a, &b, &c, &d);

    printf("O resultado é: %f", (a*b)/(c*d));

    return 0;
}
