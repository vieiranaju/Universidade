#include <stdio.h>

int main(){

    int cont, i, vet[20], vet2[20];

    for(cont = 0; cont < 20; cont++){
        scanf("%d", &vet[cont]);
    }
    cont = 10;
    for(i = 0; i<10; i++){
        vet2[cont] = vet[i];
        cont++;
    }
    cont = 0;
    for(i = 10; i<20; i++){
        vet2[cont] = vet[i];
        cont++;
    }

    for(i = 0; i< 20; i++){
        printf("%d ", vet2[i]);
    }


return 0;
}