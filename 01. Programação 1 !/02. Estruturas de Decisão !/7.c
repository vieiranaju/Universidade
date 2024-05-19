#include <stdio.h>
#include <math.h>

int main(){
    int codigo;
    float salario, reajuste;

    printf("Qual o codigo de seu cargo? \n");
    scanf("%i", &codigo);

        switch (codigo)
        {
            case 1 :
                reajuste = 1.1;
                break;
            case 2 :
                reajuste = 1.07;
                break;
            case 3 :
                reajuste = 1.12;
                break;
            case 4 :
                reajuste = 1.11;
                break;
        }

    printf("Qual seu salario atual? \n");
    scanf("%f", &salario);

    salario = salario * reajuste;

    printf("Seu salario, com o reajuste, fica %.2f", salario);
    

    
    return 0;
}