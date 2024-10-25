#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(){

    char *string, *string2;
    int i;

    string = (char *) malloc(MAX * sizeof(char));

    if(string == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

    printf("\nInsira a String: ");
    fgets(string, MAX, stdin);

    int j = 0;

    for(i = 0; string[i] != '\0'; i++){

        j++;
    }

    string2 = (char *) malloc(j * sizeof(char));

    int h = j - 1;

    for(i = 0; i < j; i++){

        string2[i] = string[h];
        h--;  

    }

    string2[i] = '\0';

    printf("%s", string2);

    free(string);
    free(string2);

    return 0;

}