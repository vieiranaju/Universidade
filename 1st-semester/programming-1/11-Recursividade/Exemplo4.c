#include <stdio.h>

int soma (int vet[], int n){

	if(n==0)
	    return vet[0];
	else
	    return vet[n] + soma(vet, n-1);

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

printf("soma dos elementos do vetor = %d\n", soma(vet, x-1));

return 0;
}
