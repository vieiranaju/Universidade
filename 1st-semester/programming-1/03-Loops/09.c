#include <stdio.h>

int main(){
    int x, i;


        printf("Escolha um numero: ");
        scanf("%i", &x);

        if(x<0){
            printf("\n Nao e um numero primo :( ");

        }

        for (i = 2; i <= x; i++) {

        if (x % i == 0) {
            printf("\nNao e um numero primo :( ");
    }   
        else{
            printf("\nE um numero primo!!");
            return 0;
        }
    }
    
    return 0;
    }