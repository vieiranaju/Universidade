#include <stdio.h>

int main(){

    int i, x, y, media;
    
        printf("Escolha uma quantidade de numeros inteiros: \n");
        scanf("%i", &x);



        for(i = 1; i<=x; i++){
            printf("escolha o valor de y\n");
            scanf("%i", &y);
            media = (media + y);
        }
        media = media/x;
        printf("\n a media e %i", media);


        
    
    
    
    
    
    
    
    
     }