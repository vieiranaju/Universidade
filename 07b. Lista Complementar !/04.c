#include <stdio.h>
#define MAX 100

int main(){

    char Nome[MAX];
    float ValorTotal;

    printf("Insira o nome do produto:\n");
    fgets(Nome, MAX, stdin);

    printf("\nInsira o Valor:\n");
    scanf("%f", &ValorTotal);



    printf("\nVoce deseja comprar %s\n", Nome);
    printf("O valor total do produto e: R$ %.1f\n", ValorTotal);
    printf("Ao Pagar a vista voce recebe R$ %.1f de desconto e o valor final seria: R$ %.1f\n", ValorTotal*0.1, ValorTotal*0.9);


return 0;
}
