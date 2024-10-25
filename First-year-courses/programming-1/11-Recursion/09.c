#include <stdio.h>

int maiorElemento(int *vet, int tam) {
    if (tam == 1) {
        return vet[0];
    }

    int maior = maiorElemento(vet, tam - 1);

    if (maior > vet[tam - 1]) {
        return maior;
    } else {
        return vet[tam - 1];
    }
}

int main (){

int x;

printf("Quantos numeros para o vetor:");
scanf("%d", &x);

int vet[x], i = 0;

while(i < x){
    
    printf("[%d]:", i);
    scanf("%d", &vet[i]);    
    i++;

}

printf("maior elemento do array = %d\n", maiorElemento(vet, x));

return 0;
}