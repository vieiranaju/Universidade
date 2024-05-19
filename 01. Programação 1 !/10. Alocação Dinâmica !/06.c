#include <stdio.h>
#include <stdlib.h>

int** matriz(int numero) {

    int **mat = (int**)calloc(numero, sizeof(int*));


    int i, j;

	// alocando cada uma das linhas da matriz
	for(i = 0; i < numero; i++)
		mat[i] = (int*)calloc(numero, sizeof(int));


    if(mat == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

    for(i = 0; i < numero; i++){

		for(j = 0; j < numero; j++){

            if(j == numero - i - 1){
                mat[i][j] = 1;
            }

        }
	}

return mat;
    
}

int main() {

    int n;

    printf("\nDigite o numero de linhas e colunas da matriz: \n");
    scanf("%d", &n);
    
    int **resultado = matriz(n);

    for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("[%d]\t", resultado[i][j]);
		printf("\n");
	}

   
    // libera cada linha
	for(int i = 0; i < n; i++)
		free(resultado[i]);

	// libera o vetor de ponteiros
	free(resultado); 

    
    
    return 0;
}