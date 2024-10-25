#include <stdio.h>
#include <math.h>

int main(){

        float a, b, c, raiz, resultado1, resultado2;
    printf("Defina valores para a,b e c em uma equação de segundo grau:\n");
    scanf("%f%f%f", &a,&b,&c);

        if (a == 0){
            printf("Nao e uma equacao de segundo grau!");
        }
        else{
            raiz = pow(b,2) - 4 * a * c;

            if(raiz>0){
                resultado1 = (-b - sqrt(raiz))/2*a;
                resultado2 = (-b + sqrt(raiz))/2*a;

                printf("Os resultados são %f e %f", resultado1, resultado2);
            }
            else if (raiz == 0) {
                resultado1 = -b / (2 * a);

                printf("O resultado da equacao e %.2f\n", resultado1);
        }
            
            else if(raiz<0){
                printf("Nao existem raizes reais");
            }
        }

        return 0;
            
        

}