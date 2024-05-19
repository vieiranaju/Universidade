#include <stdio.h>

int main(){
    int vet[10], i, x, count = 0;

    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }

    printf("Escolha um numero x\n");
    scanf("%d", &x);

    for(i = 0; i < 10; i++){
        if(vet[i] == x){
            ++count;
        }
    }

    printf("%d apareceu %d vezes!!", x, count);


}