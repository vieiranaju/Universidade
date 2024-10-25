#include <stdio.h>

int main(){

    int a, b, c, d, e, i;

    i = 0;

    printf("Responda com 0 para os itens que NÃO estão presentes no seu trabalho e 1 para os que ESTÃO presentes:\n");


    printf("De acordo com a presença dos seguintes itens no seu trabalho\n");
    printf("\ndigite 0 para os que não estão presentes e 1 para os que estiverem");

    printf("\nItens no trabalho: ");
    printf("\n___________________________________");
    printf("\n1 - Inferface grafica\n");
    scanf("%i", &a);
    printf("\n2 - Inteligencia Artificial\n");
    scanf("%i", &b);
    printf("\n3 - Encapsulamento\n");
    scanf("%i", &c);
    printf("\n4 -  Indentacao\n");
    scanf("%i", &d);
    printf("\n5 -  Structs\n");
    scanf("%i", &e);
    printf("\n___________________________________\n");

            if(a==1 || b==1){
                i++;
            }
            if(c==1 && d==1){
                i++;
            }
            if(e == 1){
                i++;
            }

            if(i == 0){
                printf("\nRequisitos insuficientes para a avaliacao");
            }
            else{
                printf("\nSeu trabalho cumpre %i requisitos e sera enviado para avaliacao", i);
            }

    return 0;
}