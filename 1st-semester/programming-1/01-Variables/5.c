
#include <stdio.h>
#include <math.h>
#define Pi 3.1415
int main(){
    printf("\nexercicio 5 !!");
    int x1, y1, x2, y2;
    float distancia;

        printf("\nQual a coordenada dos pontos A e B?\n");
        scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
            distancia = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        printf("\nA distancia entre eles é: %f", distancia);
        return 0;
}