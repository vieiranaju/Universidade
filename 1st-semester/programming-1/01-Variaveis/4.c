#include <stdio.h>
#include <math.h>

int main(){

    printf("\nexercicio 4 !!\n");
    int horas, minutos, segundos;

        printf("\nInsira as horas, os minutos e os segundos, para transformar no valor correspondente em segundos.\n");
        scanf("%d%d%d", &horas, &minutos, &segundos);
        segundos = segundos + minutos*60 + horas*60*60;
        printf("\n %d segundos !", segundos);
        return 0;
}