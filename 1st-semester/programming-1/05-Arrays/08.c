#include <stdio.h>
#define MAX 50

  int main(){
    
    int vet[MAX], i, maior = 0, menor = 0, a=0;

    for(i = 1; i<=MAX; i++){
       scanf("%d", &vet[i]);
        
        if (vet[i] == 0) {
            break;
        }
        
        a++;
    }

    for(i = 0; i< a-1; i++){
      if(vet[i] > 30){
        maior++;
      }
      if(vet[i] < 18){
        menor++;
      }
    }
      printf("%d Menores de 18 e %d maiores de 30", menor, maior);
    
      return 0;
}
