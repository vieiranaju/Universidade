#include <stdio.h>

int area(int x, int y){

  return x*y;
}

int main() {
  int x, y;
  printf("Qual o comprimento e a largura: \n");
  scanf("%i%i", &x, &y);

    printf("A area e %i", area(x, y));
  return 0;
}