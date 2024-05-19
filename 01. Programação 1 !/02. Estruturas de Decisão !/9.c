#include <stdio.h>
#include <math.h>

int main(){

        int x, y;
    printf("Insira as coordenadas: ");
    scanf("%i%i", &x, &y);

    if (x>0 && y>0){
        printf("Quadrante 1");
    }
    else if (x>0 && y<0){
        printf("Quadrante 4");
    }
    else if (x<0 && y<0){
        printf("Quadrante 3");
    }
    else{
        printf("Quadrante 2");
    }

    return 0;
}