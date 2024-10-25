#include <stdio.h>

int main(){

    int n, cont, i;

    printf("Informe um valor inteiro: ");
    scanf("%d", &n);

  int vet[n];

    for(cont = 1; cont <= n; cont++){
        printf("\nNumero:");
        scanf("%d", &vet[cont]);
    }
  
    for(i = n; i >= 1; i--){
        printf("\n%d", vet[i]);
    }


return 0;
}