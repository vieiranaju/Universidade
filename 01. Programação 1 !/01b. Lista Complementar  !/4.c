#include <stdio.h>
#include <math.h>

int main(){

    float valor;

    printf("Insira o valor gasto: ");
    scanf("%f", &valor);

    printf("O valor a ser pago é: %.2f", valor * 1.10);

    return 0;
}