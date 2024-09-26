#include <stdio.h>

int main(){

    int n, i;
    float s = 0;

        printf("Determine um valor: ");
        scanf("%i", &n);

    for(i = 1; i <= n; i++){
        s = s + ((float)1/i);
    }

    printf("%f", s);

    return 0;
}