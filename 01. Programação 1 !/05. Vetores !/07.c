#include <stdio.h>

  int maior(int vet[], int n){
    int maior = 0, i;

    for(i=0; i<n; i++){
      if(vet[i] > maior){
        maior = vet[i];
      }
    }
    return maior;
  }

  int main(){

    int n, i;

    printf("Insira um valor inteiro: ");
      scanf("%d", &n);

    int vet[n];

    printf("Insira os %d numeros!",n);

    for(i=0; i<n; i++){
      scanf("%d", &vet[i]);
    }

    printf("O maior valor é %d", maior(vet, n));
        
        
  

  return 0;
}
