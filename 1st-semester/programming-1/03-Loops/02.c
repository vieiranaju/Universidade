#include <stdio.h>

int main(){


    int x, y;


        printf("Escolha dois valores: ");
        scanf("%i%i", &x, &y);

    if(x<y){
        while(x<=y){
            if(x %5 == 2||x %5 == 3){
                printf("%i\n", x);
            }
            x++;
        }
    }
    else{
        while(y<=x){
            if(y %5== 2||y %5== 3){
                printf("%i\n", y);
            }
             y++;

        }
    }




    return 0;
}