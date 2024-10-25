#include <stdio.h>
#include <math.h>

int main(){

        int tipo;
        float km, consumo;

    printf("\nVeiculo A = 1\n");
    printf("\nVeiculo B = 2\n");
    printf("\nVeiculo C = 3\n");

    printf("Insira o tipo de veiculo: \n");
    scanf("%i", &tipo);

    printf("Quantos km foram percorridos?\n");
    scanf("%f", &km);

    switch (tipo)
    {
    case 1:
        consumo = km/15;
        break;

    case 2:
        consumo = km/12;
        break;

    case 3:
        consumo = km/10;
        break;
    }

    printf("O consumo de combustivel foi %.2fL", consumo);



    return 0;
}