#include <stdio.h>
#include <math.h>

int main(){

        int a, b, c;

    printf("Insira tres valores inteiros: \n");
    scanf("%i%i%i", &a, &b,&c);

    if (a > b && a > c){
        if(b<c){
            printf("\n%i\n%i\n%i", a, c, b);
        }
        else {
            printf("\n%i\n%i\n%i", a, b, c);
        }
    }
    else if (b > a && b > c){
        if(a<c){
            printf("\n%i\n%i\n%i", b, c, a);
        }
        else {
            printf("\n%i\n%i\n%i", b, a, c);
        }
    }
    else if (c > b && c > a){
        if(a<b){
            printf("\n%i\n%i\n%i", c, b, a);
        }
        else {
            printf("\n%i\n%i\n%i", c, a, b);
        }
    }

    else{
        printf("numeros invalidos ou iguais");
    }

    return 0;
}