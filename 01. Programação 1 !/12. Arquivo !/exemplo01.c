//Abrindo e Fechando um Arquivo

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arq; // Ponteiro para acessar o arquivo
    arq = fopen("teste.txt", "wb");//abrir arquivo

    if (arq == NULL){
        printf("Erro");
        exit (1);
    }

    printf("Sucesso!");
    fclose(arq); // fecha

    return 0;
}