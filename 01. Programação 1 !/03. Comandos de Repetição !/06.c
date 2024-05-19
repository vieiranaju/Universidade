#include <stdio.h>

int main(){

    int x, menos = 0, mais = 0;

    x=1;
    
    while(x!=0){
        scanf("%x", &x);

        if(x>29){
            mais++;
        }

        else if(x<19){
            menos++;
        }
    }

    printf("Menos de 18: %i \n Mais de 30: %i\n", menos, mais);
    
    
    
    }