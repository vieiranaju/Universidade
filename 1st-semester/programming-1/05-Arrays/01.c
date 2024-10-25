#include <stdio.h>

int ultimo(int x, int vet[]){
    int i, count = 0, y = vet[x];

    for(i = 1; i <= x; i++){
        if(vet[i] == y){
            count++;
        }
    }
    return count;

}
int main(){
    int n, i;

    printf("Escolha a quantia de valores para armazenar");
    scanf("\n%d", &n);

    int vet[n];

    for(i = 1; i <= n; i++){
        scanf("\n%d", &vet[i]);
    }
    printf("\n%d apareceu %d vezes!!", vet[n], ultimo(n, vet));

  return 0;
}