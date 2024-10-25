#include <stdio.h>
#define MAX 100

int main(){

    char String[MAX + 1], Invert[MAX + 1];
    int i, j=0;

    printf("Escreva uma frase:\n");
    fgets(String, MAX+1, stdin);

    for(i = 0; String[i] != '\0'; i++){

            j++;

    }
    for(i = 0; String[i] != '\0'; i++){
        Invert[j - 1] = String[i];
        j--;
    }

    Invert[i] = '\0';

    printf("%s", Invert);


return 0;
}
