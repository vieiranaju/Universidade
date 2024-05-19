#include <stdio.h>

int main(){
        int n, i;
        // i = 0;
    printf("Escolha um valor inteiro: \n");
    scanf("%i", &n);

     //while(i<=10){
        //printf("\n%i x %i = %i",i,n,i*n);
        //i++;    }

   // do{
       // printf("\n%i x %i = %i",i,n,i*n);
       // i++;
   // }while(i<=10);

    for (i = 0; i<=10; i++) {
        printf("\n%i x %i = %i",i,n,i*n);
      
    }

    
    return 0;


}