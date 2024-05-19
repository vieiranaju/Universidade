#include <stdio.h>
#include <math.h>

int main(){

    int num;
    float valor, horas;

    printf("Insira seu cadastro de funcionario: ");
    scanf("%i", &num);

    printf("\nOk, %i, quanto você recebe por hora?", num);
    scanf("%f", &valor);

    printf("\nQual seu total de horas trabalhadas? ");
    scanf("%f", &horas);

    printf("\nSeu salario foi %,2f, funcionario %i",valor*horas ,num);




    return 0;
}