#include <stdio.h>

int main(){

    int x, i = 0, media = 0;
    
    while(x!=0){
        scanf("%d", &x);

        if( x > 10 && x < 50 && x % 7 == 0 ){
            i++;
            media = media + x;
        }
    }

    printf("A media dos %i multiplos de 7 é %i \n ", i, media/i);
    
    
    
    }