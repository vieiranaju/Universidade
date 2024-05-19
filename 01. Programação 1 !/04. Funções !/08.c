#include <stdio.h>

int num(int x) {
int cont, i = 0;

for(cont = 1; cont <= x; cont++){
    if(x % cont == 0){
        printf("%i ", cont);
        i++;
    }
}
return i;

}

int main() {
        int y;

    printf("Escolha um numero: ");
    scanf("%i", &y);

    printf("Existem %i divisores", num(y));
 
  return 0;
}