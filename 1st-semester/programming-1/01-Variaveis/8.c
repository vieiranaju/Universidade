#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main(){

    printf("\nexercicio 8 !!");
    float salarioBase, imposto, gratificacao;

        printf("\nQual o salario?\n");
        scanf("%f", &salarioBase);
            imposto = salarioBase*0.12;
            gratificacao= 50;
            salarioBase = salarioBase - imposto + gratificacao;
        printf("O salario final é: %f", salarioBase);

         return 0;
}