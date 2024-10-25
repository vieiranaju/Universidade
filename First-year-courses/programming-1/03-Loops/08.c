#include <stdio.h>

int main(){
    int x = 1, i;
        

        while(x<=10){
            for(i = 1; i<=10;i++){
                printf("\n%i x %i = %i", x, i, x*i);
            }
            x++;
        }
    }