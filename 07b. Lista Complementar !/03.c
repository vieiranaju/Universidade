
#include <stdio.h>
#include <ctype.h>
#define MAX 100

void Caractere(char *String, char caractere){
    int i, j = -1;

    for(i = 0; String[i] != '\0'; i++){
        if(tolower(String[i]) == caractere){
            printf("\n'%c'Aparece na posicao %d\n", caractere, i + 1);
            j++;
            }
    }

    if (j + 1> 0){
        printf("\nExistem %d %c !",j + 1, caractere);
    }

    else{
        printf("\n%d", j);
    }
}
int main(){

    char String[MAX + 1], caractere;
    int i, j=0;

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);

    printf("Escreva um caractere:\n");
    scanf("%c", &caractere);


    Caractere(String, caractere);

return 0;
}



