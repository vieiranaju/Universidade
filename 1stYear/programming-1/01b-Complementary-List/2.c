#include <stdio.h>
#include <math.h>

int main(){
        float base, altura;

        printf("Insira a base e a altura de um triangulo para calcular sua area: ");
        scanf("%f%f", &base, &altura);

        printf("A altura do triangulo é: %f", (base*altura)/2);
        
    return 0;
}
