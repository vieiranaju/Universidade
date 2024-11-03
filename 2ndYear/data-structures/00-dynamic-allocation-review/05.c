#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto{

    float x, y;

}ponto;

int main(){

    int n, indice = 0;
    float distMenor = 100000;

    printf("INFORME QUANTOS PONTOS VOCE QUER: ");
    scanf("%d", &n);

    
    ponto *a = (ponto *) calloc(n+1, sizeof(ponto));

     if (a == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }

    for(int i = 0; i<n; i++){

        printf("Preencha o ponto %d: ", i);
        scanf("%f %f", &a[i].x, &a[i].y);
        a[n].x += a[i].x;
        a[n].y += a[i].y;
        
    }

    a[n].x /= n;
    a[n].y /= n;

    printf("\nX: %.2f\nY: %.2f", a[n].x, a[n].y);

    for(int i = 0; i<n; i++){

        float distancia = sqrt(pow(a[i].x - a[n].x,2) + pow(a[i].y - a[n].y,2));

        if(distancia < distMenor ){
            distMenor = distancia;
            indice = i;
        }

        

    }

    printf("\n");
    printf("\nDistancia do Ponto Medio: %.2f", distMenor);
    printf("\nIndice: %d", indice);

    free(a);

    return 0;
}
