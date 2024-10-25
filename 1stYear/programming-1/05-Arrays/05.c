#include <stdio.h>

  int main(){
      int x = 1, i = 1, vet[50], y;

      while(x != -1){
        scanf("%d", &x);
        
        if(x > 9 && x <51){
          vet[i] = x;
          i++;
        }
        else if(x == -1){
          break;
        }
      }

    printf("Existem %d numeros entre 10 e 50, são eles: ", i);
    for (y = 1; y <= i; y++){
      printf("%d ", vet[y]);
    }
  

  return 0;
}