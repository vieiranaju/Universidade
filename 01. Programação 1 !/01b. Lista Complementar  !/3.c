#include <stdio.h>
#include <math.h>

int main(){
    float altura, massa;

    printf("Insira sua altura e massa para calcular o IMC: \n");
    scanf("%f%f", &altura, &massa);

    printf("O IMC é: %f", massa / pow(altura,2));
    return 0;
}