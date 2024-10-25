
#include <stdio.h>
#define TAM 5

void mult(int vet[]){
  int i, count = 0;

  for(i = 1; i <= TAM; i++){
        if(vet[i] %7 == 0){
            count++;
        }
    }

    int vet2[count], a = 0;

    for(i = 0; i < TAM; i++){
      if(vet[i] %7 == 0){
            vet2[a] = vet[i];
            a++;
        }}

        printf("\nOs multplos de 7 sao: ");
        for(i = 0; i < a; i++){
        printf("%d ", vet2[i]);
    }
    
}

int main(){
    int i, vet[TAM];

    printf("Insira %d numeros:\n", TAM);
  
    for(i = 1; i <= TAM; i++){
        scanf("\n%d", &vet[i]);
    }
    
    mult(vet);


  return 0;
}