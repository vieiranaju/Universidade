#include <stdio.h>

int segundos(int x, int y, int z){

  return (x*60)+(y*60*60) + z;
}

int main() {
  int hr, min, seg;
  printf("Horas, minutos e segundos: \n");
  scanf("%i%i%i", &hr, &min, &seg);

    printf("Corresponde a %i segundos", segundos(hr, min, seg));
  return 0;
}