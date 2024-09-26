#include <stdio.h>

int soma (int vet[], int n, int i){

	if(i==n)
	    return vet[0];
	else
	    return vet[i] + soma(vet, n, i + 1);

}

int main (){

int x, j = 0;

printf("Quantos numeros para o vetor:");
scanf("%d", &x);

int vet[x], i = 0;

while(i < x){
    
    printf("[%d]:", i);
    scanf("%d", &vet[i]);    
    i++;

}

printf("soma dos elementos do vetor = %d\n", soma(vet, x-1, j));

return 0;
}