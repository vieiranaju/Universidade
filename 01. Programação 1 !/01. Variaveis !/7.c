#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main(){
    printf("\nexercicio 7 !!");
    int valor, troco;

        printf("\nQual a quantidade em dinheiro colocada?\n ");
        scanf("%d", &valor);
            troco = valor%7;
        printf("\nSua perda, %d, nossa alegria !", troco);

         return 0;

}