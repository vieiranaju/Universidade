#include <stdio.h>
#include <math.h>

int main(){

        int codigo, quantidade;
        float valor, valorF, desconto;

    printf("Qual o codigo do produto? \n");
    scanf("%i", &codigo);

        switch (codigo)
        {
            case 1 :
                valor = 5.30;
                break;
            case 2 :
                valor = 6.00;
                break;
            case 3 :
                valor = 3.20;
                break;
            case 4 :
                valor = 2.50;
                break;
        }
    
    printf("Qual a quantidade de produto? \n");
    scanf("%i", &quantidade);

    valorF = quantidade * valor;
    desconto = valorF * 0.15;

    if(quantidade >= 15 || valor >= 40){
        valorF = valorF - desconto;
    }
     
     printf("O valor a ser pago é %.2f", valorF);


    return 0;
}