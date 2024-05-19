
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main(){

    char String[MAX + 1];
    int i, j=0;

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);

    for(i = 0; String[i] != '\0'; i++){
        if(tolower(String[i]) == 'a' || tolower(String[i]) == 'e' ||tolower(String[i]) == 'i'
            ||tolower(String[i]) == 'o' ||tolower(String[i]) == 'u'){
            String[i] = '*';
            }
    }




    printf("%s", String);


return 0;
}


