#include <stdio.h>
#include <ctype.h>

int main(){
    char caractere, letra;

    printf("Escreva uma letra:\n");
    scanf("%c", &caractere);

    letra = tolower(caractere);

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ){
        printf("É uma vogal !");

    }

    else{
        printf("Não é uma vogal !");
    }

    
}