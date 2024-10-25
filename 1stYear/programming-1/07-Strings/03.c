#include <stdio.h>
#define MAX 100

int Space(char *String){
    int i, j = 0;

    for(i = 0; String[i] != '\0'; i++){
        if(String[i] == ' '){
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



    printf("existem %d espacos", Space(String));


return 0;
}

