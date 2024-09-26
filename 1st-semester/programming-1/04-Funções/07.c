#include <stdio.h>

void tabuada(int x) {
int cont;

for(cont = 1; cont <= 10; cont++){
    printf("%i x %i = %i\n", x, cont, x*cont);
    }
}


int main() {
        int y;

    printf("Escolha um numero para calcular sua tabuada:\n");
    scanf("%i", &y);

    tabuada(y);
 
  return 0;
}