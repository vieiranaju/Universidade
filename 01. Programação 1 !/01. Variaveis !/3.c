#include <stdio.h>
int main()
{ 
printf("\nexercicio 3 !!\n");
    float item, euro, dolar;

        printf("\nInsira o valor de um produto:\n ");
        scanf("%f", &item);
        printf("\nInsira o valor atual do dolar:\n ");
        scanf("%f", &dolar);
        printf("\nInsira o valor do euro:\n ");
        scanf("%f", &euro);
            euro = euro * item;
            dolar = dolar * item;
        printf("\nem dolar, o valor ficou %.2f, ja em euro %.2f", dolar, euro);
}