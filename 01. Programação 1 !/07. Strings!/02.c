
#include <stdio.h>
#include <ctype.h>
#define MAX 100


void criptografia(char *String){

    int i, j;
    char String2[MAX];

    for(i = 0; String[i] != '\0'; i++){
        if(String[i] >= 'a' && String[i] <= 'z'){
            j = String[i] - 'a';
            String2[i] = 'z' - j;
            }
        else if(String[i] >= 'A' && String[i] <= 'Z'){
            j = String[i] - 'A';
            String2[i] = 'Z' - j;
            }
        else{
            String2[i] = String[i];
        }
    }
    String2[strlen(String + 1)] = '\0';
    printf("\n %s", String2);
}

int main(){

    char String[MAX + 1];

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);

    criptografia(String);

return 0;
}


