#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c;

        printf("Insira 3 valores:\n");
        scanf("%f%f%f", &a,&b,&c);

        printf("\n(a*b)/c = %.2f", (a*b)/c);
        printf("\n(a^2 + b + 5c = %.2f", pow(a,2) + b + 5*c);
        printf("\n(a*b*c + b + c/3 *5 - 1 = %.2f", a * b * c + b * (c/3) * 5 - 1);
        printf("\n(a*b*c)^3/2 = %.2f", pow(a*b*c,3)/2);
    


    return 0;
}
