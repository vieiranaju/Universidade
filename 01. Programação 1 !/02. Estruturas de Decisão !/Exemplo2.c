#include <stdio.h>
#include <math.h>

int main(){
    float x, y;
    char op;

    printf("Digite um numero, um operador e outro numero, para calcular !!\n\n");
        scanf("%f %c %f", &x, &op, &y);
        //Avalia a expressão e determina o comando correspondente
        switch (op)
        {
        case '-':
            printf("A subtração de %.2f e %.2f é %.2f", x, y, x-y);
            break;

        case '+':
            printf("A adição de %.2f e %.2f é %.2f", x, y, x+y);
            break;

        case '/':
            printf("A divisão de %.2f e %.2f é %.2f", x, y, x/y);
            break;

        case '*':
            printf("A multiplicação de %.2f e %.2f é %.2f", x, y, x*y);
            break; //pra terminar usa o break !!
        
        default:
            printf("Operador desconhecido !");
        }
}