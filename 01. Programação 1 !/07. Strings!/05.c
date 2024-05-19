#include <stdio.h>
#include <ctype.h>
#define MAX 100

int Vogais(char *String){
    int i, j = 0;

    for(i = 0; String[i] != '\0'; i++){
        if(tolower(String[i]) == 'a' || tolower(String[i]) == 'e' ||tolower(String[i]) == 'i'
            ||tolower(String[i]) == 'o' ||tolower(String[i]) == 'u'){
            j++;
            }
    }

    return j;
}
int main(){

    char String[MAX + 1];
    int i, j=0;

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);



    printf("existem %d vogais", Vogais(String));


return 0;
}


