#include <stdio.h>
#define MAX 100

int main(){

    char String[MAX + 1], String2[MAX + 1];
    int i, j=0, h;

    printf("Escreva a primeira frase:\n");
    fgets(String, MAX+1, stdin);

    printf("Escreva a segunda frase:\n");
    fgets(String2, MAX+1, stdin);

    for(i = 0; String[i] != '\0'; i++){
        if(String[i] != String2[i]){
            h = 0;
            break;
    }
     h = 1;
    }

    if(h == 0){
        printf("Sao diferentes!");
    }
    else{
        printf("Sao iguais!");
    }

return 0;
}

