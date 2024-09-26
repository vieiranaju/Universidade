#include <stdio.h>
#include <math.h>

int main(){

        float saldoMedio, credito;

    printf("Insira seu saldo medio do ano: \n");
    scanf("%f", &saldoMedio);

    if(saldoMedio>400){
        credito = saldoMedio * 0.30;
    }

    else if(saldoMedio>300){
        credito = saldoMedio * 0.25;
    }
    else if(saldoMedio>200){
        credito = saldoMedio * 0.2;
    }
    else if(saldoMedio<=200){
        credito = saldoMedio * 0.1;
    }

    printf("Seu credito é %.2f !", credito);

    return 0;
}