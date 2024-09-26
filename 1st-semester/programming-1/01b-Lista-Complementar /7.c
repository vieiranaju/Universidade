#include <stdio.h>
#include <math.h>

int main(){

    float diaria, dias, km;
    diaria = 30;

    printf("Ola, insira quantos dias ficou com o carro e quantos kilometros rodou: ");
    scanf("%f%f", &dias, &km);

    printf("\nO valor a ser pago é: %f", (diaria*dias + km*0.01)*0.9);
    return 0;
}