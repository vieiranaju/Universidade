#include <stdio.h>
#include <math.h>

float seg(float a, float b, float c){
    float raiz;
  
             raiz = pow(b,2) - 4 * a * c;
              return raiz;

        }
int main() {
  float x;
  float a, b, c, resultado1, resultado2;
    printf("Defina valores para a,b e c em uma equação de segundo grau:\n");
    scanf("%f%f%f", &a,&b,&c);

        if( a == 0){
          printf("Não é uma equação de segundo grau!");
        }
  
          x = seg(a, b, c);
            

            if(x>0){
                resultado1 = (-b - sqrt(x))/(2*a);
                resultado2 = (-b + sqrt(x))/(2*a);

                printf("Os resultados são %f e %f", resultado1, resultado2);
            }
            else if (x == 0) {
                resultado1 = -b / (2 * a);

                printf("O resultado da equacao e %.2f\n",resultado1);
        }
            else if(x<0){
                printf("Nao existem raizes reais");
            }
  
        
  return 0;
}
