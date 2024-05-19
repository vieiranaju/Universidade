#include <stdio.h>

void binario(int n){
    
    if (n > 1)
        binario(n / 2);
    
    printf("%d", n % 2);

}

int main (){

int x;

printf("valor:");
scanf("%d", &x);

    binario(x);
    printf("\n");

    return 0;


}
