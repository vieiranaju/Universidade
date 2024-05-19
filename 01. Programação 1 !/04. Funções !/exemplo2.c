#include <stdio.h>

int num(int n) {
  int i;
  if (n > 0) {
    i = 0;
  } else {
    i = 1;
  }
  return i;
}

int main() {
  int x, y;
  printf("Escolha um numero: \n");
  scanf("%i", &x);

  y = num(x);

  if (y == 0) {
    printf("Numero positivo!!");
  }

  else {
    printf("Numero negativo!!");
  }
  return 0;
}