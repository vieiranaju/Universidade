#include <stdio.h>

int main(){
    
    int x = 2, i;
    scanf("%d", &x);

    if(x > 0){
        //Condicional que o valor inserido tem que ser positivo e diferente de 0
        for(i = 2; i<x; i++){
        //laço de repetição para verificar se é primo ou não
            if(x %i == 0){
                //se o valor inserido for dividido por outro numero, diferente de 1 e diferente dele mesmo, então não é
                printf("Não");
                return 0;
                //encerra o programa
            }
        }
        printf("Sim");
        //se o programa não foi encerrado,então é primo!!
    }

    return 0;
}