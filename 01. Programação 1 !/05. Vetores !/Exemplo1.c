#include <stdio.h>
#define TAM 100
// troca todos os locais com "TAM" por 100
int const MAX = 50;
// valor constante

int main() {
    //vetores armazenam diversos dados que podem ser acessados por uma mesma variavel

    //float notas[5] = {6.0, 7.0, 8.0, 9.0, 10.0};
    //inicializando com um valor determinado 

    //int a[TAM];
    // = 100
    //int b[TAM + 1];
    // = 100 + 1

    //float c[MAX];
    //MAX é uma variavel constante 

    int n, i, media = 0;

    printf("Escolha a quantidade de notas para armazenar!!");
    scanf("%d", &n);

    int x[n];

    //int x[5];
    //int y[5];
    // y[5] = x[5] --> da erro, tem que fazer um por um >:]

    for(i = 0; i< n; i++){
        printf("Insira as notas\n");
        scanf("%d", &x[i]);
        media += x[i];
    }

    media /= n;
    printf("A media é %d", media);

    for(i = 0; i<n;i++){
        if(x[i] > media){
            printf("Notas: %d", x[i]);
        }
    }



    return 0;
}
