#include <stdio.h>

int maior(int x, int y, int z) {
     int i;

     i = x;

  if (i < y) {
    i = y;
  } 
  if( i < z) {
    i = z;
  }

  return i;
}

int main() {
  int x, y, z;
  printf("Escolha tres numeros: \n");
  scanf("%i%i%i", &x, &y, &z);

    printf("O maior é %i", maior(x, y, z));
  return 0;
}