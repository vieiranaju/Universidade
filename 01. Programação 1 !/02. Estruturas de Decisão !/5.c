#include <stdio.h>
#include <math.h>

int main(){
    float l1, l2, l3;
    printf("Insira os lados de um triangulo:\n");
    scanf("%f%f%f", &l1,&l2,&l3);

        if(l1 == l2 && l2 == l3){
            printf("E um triangulo equilatero");
        }

        else if((l1 == l2 && l1 != l3 )||( l1 == l3 && l1 != l2 )||( l3 == l2 && l1 != l1 )){
            printf("E um triangulo isosceles");

        }

        else{
            printf("E um triangulo escaleno");
        }
    return 0;
}