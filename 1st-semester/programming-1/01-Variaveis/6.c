#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main(){

    printf("\nexercicio 6 !!");
    int a, b, aux;

        printf("\nEscolha Valores para A e B: \n");
        scanf("%i%i", &a, &b);
            aux = a;
            a = b;
            b = aux;
        printf("\nA=%i e B=%i", b, a);
        printf("\nA=%i e B=%i", a, b);

         return 0;
}