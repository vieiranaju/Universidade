#include <stdio.h>
#define TAM 50

int main() {
  int i, vet[TAM], p = 0, im = 0;

  printf("Digite os valores em sequencia: ");
  for (i = 0; i < TAM; i++) {
    scanf("%d", &vet[i]);
    if (vet[i] % 2 == 0) {
      p++;
    } 
    else if (vet[i] % 2 != 0) {
      im++;
    }
  }
  int par[p], impar[im];
  int x = 0, y = 0;
  
  for (i = 0; i < TAM; i++) {
    if (vet[i] % 2 == 0) {
      par[x] = vet[i];
      x++;

    } else if (vet[i] % 2 != 0) {
      impar[y] = vet[i];
      y++;
    }
  }
    printf("____________________________________________\n");
    printf("Existem %d numeros impares e %d pares!\n", im, p);

       printf("impares:\n");
      for(i = 0; i<im; i++){
        printf("%d ", impar[i]);
      }

      printf("\npares:\n");
      for(i = 0; i<p; i++){
        printf("%d ", par[i]);
      }


  return 0;
}