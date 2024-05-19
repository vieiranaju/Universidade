#include <stdio.h>

int num(int x) {
int cont, i = 0;

for(cont = 1; cont <= x; cont++){
    if(x % cont == 0){
        i++;
    }
}

if(i == 2){
    return 1;
}
else{
    return 0;
}

}

int main() {
        int y;

    printf("Escolha um numero: ");
    scanf("%i", &y);

    if(num(y) == 0){
        printf("nao e primo !!");
    }

    else{
        printf("e primo !!");
    }
 
  return 0;
}