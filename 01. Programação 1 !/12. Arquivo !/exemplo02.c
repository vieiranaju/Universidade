//Gravando em um Arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];
    FILE *arq; // Ponteiro para acessar o arquivo

    arq = fopen("teste.txt", "w");//abrir arquivo

    if (arq == NULL){
        printf("Erro");
        exit (1);
    }

    printf("String a ser gravada!");
    fgets(string, 100, stdin); // Lê a string do usuário

    //size_t length = strlen(string); // Armazena o comprimento da string

    // Grava a string no arquivo
    //for (size_t i = 0; i < length; i++)
    //    fputc(string[i], arq);

    int resultado = fputs ( string , arq );

    if ( resultado == EOF ) // verifica se houve erro
        printf (" Erro na gravacao\n");
    else
        printf (" Gravacao feita com sucesso !!!\n");

    fclose(arq); // fecha

    return 0;
}