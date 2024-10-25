#include <stdio.h>
#include <math.h>

int main(){

        double altura;
        int idade, quant;

        quant = 0;

    printf("Insira sua idade e altura: \n");
    scanf("%lf%i", &altura, &idade);

        if(altura>= 1.5 && idade >= 12){
            printf("Pode andar na Barca Viking! \n");
            quant++;
        }

        if(altura>= 1.4 && idade >= 14){
            printf("Pode andar no Elevator of Death! \n");
            quant++;
        }

        if(altura>= 1.7 && idade >= 16){
            printf("Pode andar no Final Killer:! \n");
            quant++;
        }

        printf("Pode andar em %i brinquedo(s) !", quant);

    return 0;
}