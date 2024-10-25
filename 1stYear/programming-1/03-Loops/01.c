#include <stdio.h>

int main(){
    int x, y, i;

        printf("Escolha dois valores: ");
        scanf("%i%i", &x, &y);


        for(i = x; i<=y; i++){
            if(i %2!= 0){
                printf("%i", i);
            }
        }

}