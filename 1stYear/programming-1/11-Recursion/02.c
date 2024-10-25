#include <stdio.h>

void paresCrescente(int n, int i){


    if (n < 0) {
        printf("O número fornecido não é um inteiro positivo.\n");
        return;
    }

	if (i == n) {
        return;
    }

	if (i % 2 == 0) {
        printf("%d ", i);
    }

    paresCrescente(n, i + 1);
}

int main (){

int x, i = 1;

printf("valor:");
scanf("%d", &x);

printf("Numeros pares Crescentes ate %d: ", x);
    paresCrescente(x, i);
    printf("\n");

    return 0;


}
