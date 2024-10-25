#include <stdio.h>

int main(){

    int mult = 1, x;
    
    do{
        scanf("%d", &x);
        if(x == 0){
            // verificar se o valor inserido é 0, e se for finalizar o laço de repetiição
            break;
        }
        else{
            mult = mult * x;
            // calcula o produto dos numeros indicados pelo usuario e armazena em uma variavel
            }
    }while(x != 0);
    // se repete enquanto o valor inserido fordiferente de 0

    printf("O resultado é %d", mult);
    //mostra o resultado
    return 0;
}