#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main(){
    printf("\nexercicio 9 !!");
    float Diaria, desconto, ocupacao;
        printf("Qual o valor da diaria? ");
        scanf("%f", &Diaria);
            desconto = Diaria * 0.35;
        printf("\nO valor com desconto é: %f", Diaria-desconto);
        printf("\nO valor arrecadado com o dobro de ocupação e o desconto será: ");
            ocupacao = 45;
        printf("%.2f", ocupacao*0.70*(Diaria-desconto));
        printf("\nSem o desconto, com metade da ocupação:");
         printf("%.2f", Diaria*ocupacao*0.35);
          return 0;
}