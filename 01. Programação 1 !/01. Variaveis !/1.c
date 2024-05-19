#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main()
{       printf("exercicio 1 !!");
    int raio;
    double perimetro, area;
        printf("Insira o raio do circulo: ");
        scanf("%d", &raio);
            area = (Pi * pow(raio,2));
            perimetro = (2 * Pi * raio);
        printf("A Area é: %.2lf", area);
        printf("\nO perimetro é: %.2lf", perimetro);

    return 0;
}