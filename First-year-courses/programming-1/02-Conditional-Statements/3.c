#include <stdio.h>

int main(){

    float a, b, c, media;
    int i = 0;

        printf("Escolha 3 valores reais e positivos para A, B e C\n");
            scanf("%f%f%f", &a, &b, &c);

            media = (a + b + c)/3;

        if(a > media){
            printf("\nA e maior que a media!");
            i++;
        }

        if(b > media){
            printf("\nB e maior que a media!");
            i++;

        }
        if(c > media){
            printf("\nC e maior que a media!");
            i++;

        }
        printf("\n%i estao acima da media!!", i);

    return 0;
}