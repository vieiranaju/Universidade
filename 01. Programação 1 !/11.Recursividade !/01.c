#include <stdio.h>

void paresDecrescente(int n){

    if (n < 0) {
        printf("O número fornecido não é um inteiro positivo.\n");
        return;
    }

	if (n == 0) {
        return;
    }

	if (n % 2 == 0) {
        printf("%d ", n);
    }

    paresDecrescente(n - 1);
}

int main (){

int x;

printf("valor:");
scanf("%d", &x);

printf("Numeros pares decrescentes ate %d: ", x);
    paresDecrescente(x);
    printf("\n");

    return 0;


}
