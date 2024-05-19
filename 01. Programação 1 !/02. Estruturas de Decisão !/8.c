#include <stdio.h>
#include <math.h>

int main(){

        int ope;
        float x, y, res;

    printf("____________________________________________");
    printf("\nInsira 1 para calcular a media aritmetica");
    printf("\nInsira 2 para calcular a diferença");
    printf("\nInsira 3 para calcular o produto");
    printf("\nInsira 4 para calcular a divisão");
    printf("\n____________________________________________");

    printf("\nQual a operacao que deseja realizar?");
    scanf("%i", &ope);

    printf("Quais os numeros escolhidos? \n");
    scanf("%f%f", &x, &y);

        switch (ope)
        {
            case 1:
                res = (x+y)/2;
                break;
            
            case 2:
                res = x - y;
                break;
            
            case 3:
                res = x * y;
                break;

            case 4: 
                if (y>0)
                {
                    res = x/y;
                }
                else{
                    printf("Nao e possivel realizar");
                    return 0;
                }
                break;
        }

    printf("\nO resultado é %.1f", res);

    return 0;
}