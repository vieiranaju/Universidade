#include <stdio.h>
#include <ctype.h>
#define MAX 100

int Caractere(char *String, char caractere){
    int i, j = 0;

    for(i = 0; String[i] != '\0'; i++){
        if(tolower(String[i]) == caractere){
            j++;
            }
    }

    return j;
}
int main(){

    char String[MAX + 1], caractere;
    int i, j=0;

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);

    printf("Escreva um caractere:\n");
    scanf("%c", &caractere);



    printf("existem %d %c", Caractere(String, caractere), caractere);


return 0;
}



