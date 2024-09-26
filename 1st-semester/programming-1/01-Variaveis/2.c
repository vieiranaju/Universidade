#include <stdio.h>
int main()
{ 
    printf("\nexercicio 2 !!");
    float nota1, nota2, nota3, nota4, media;

        printf("Insira as notas: ");
        scanf("\n%f\n%f\n%f\n%f", &nota1, &nota2, &nota3, &nota4);
            media = (nota1*1.5)+(nota2*2)+ (nota3*3)+(nota4*3.5);
            media = media/10;
        printf("A média é: %f", media);

         return 0;
}