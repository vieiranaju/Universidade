#include <stdio.h>

int main(){

int a, b, c, menor;

printf("Escolha 3 valores inteiros para A, B e C\n");
scanf("%i%i%i", &a, &b, &c);

    menor = a;

if (b<c){
if (b < menor){
    menor = b;
}
}
else{
    if(c<menor){
        menor = c;
         }
}

printf("O menor valor é %i", menor);





}