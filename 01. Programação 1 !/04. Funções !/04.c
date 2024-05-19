#include <stdio.h>


int pot(int a, int b){
    int i, p = 1;
  

    for(i = 1; i<=b; i++){
        p *= a;
    }

    return p;


        }


int main() {
  int a, b, x;
    printf("Defina dois valores:\n");
    scanf("%i %i", &a,&b);
  
          x = pot(a, b);

          printf("O resultado é %i",x);
  
        
  return 0;
}