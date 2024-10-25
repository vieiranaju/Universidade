#include <stdio.h>
#include <math.h>

int main(){
    float x, y, menor;

    printf("\nInsira dois valores:\n ");
        scanf("%f%f", &x,&y);
            /*
            if (x>y){
                printf("%f", x);
            }

            else{
                printf("%f", y);
            }
            */
            menor = (x>y) ? x:y;
    printf("%f", menor);

}