#include <stdio.h>
#include <stdlib.h>

int** somaMatriz(int **array, int **array2, int linha, int coluna) {

    int **soma = (int**)malloc(linha * sizeof(int*));

    for(int i = 0; i < linha; i++)
		soma[i] = (int*)malloc(coluna * sizeof(int));

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++){

            soma[i][j] = array[i][j] + array2[i][j];
           
            }
    
}

return soma;
    
}

int main() {

    int **mat, **mat2, lin, col;

    printf("\nDigite o numero de linhas das matrizes: \n");
    scanf("%d", &lin);

    printf("\nDigite o numero de colunas das matrizes:\n");
    scanf("%d", &col);

	// alocando o vetor de ponteiros
	mat = (int**)malloc(lin * sizeof(int*));
    mat2 = (int**)malloc(lin * sizeof(int*));


    int i, j;

	// alocando cada uma das linhas da matriz
	for(i = 0; i < lin; i++)
		mat[i] = (int*)malloc(col * sizeof(int));

    for(i = 0; i < lin; i++)
		mat2[i] = (int*)malloc(col * sizeof(int));


    if(mat == NULL || mat2 == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

    printf("\nPreencha a primeira Matriz\n ");
	// preenchendo a matriz

	for(i = 0; i < lin; i++){

		for(j = 0; j < col; j++){

            printf("\nNumero [%d %d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);

        }
	}

     printf("\nPreencha a segunda Matriz\n ");
	// preenchendo a matriz
	for(i = 0; i < lin; i++){

		for(j = 0; j < col; j++){

            printf("\nNumero [%d %d]: ", i+1, j+1);
            scanf("%d", &mat2[i][j]);

        }
	}

    printf("\n");
    
    int **resultado = somaMatriz(mat, mat2, lin, col);

    for(i = 0; i < lin; i++)
	{
		for(j = 0; j < col; j++)
			printf("[%d]\t", resultado[i][j]);
		printf("\n");
	}



    // libera cada linha
	for(i = 0; i < lin; i++)
		free(mat[i]);

	// libera o vetor de ponteiros
	free(mat); 

    for(i = 0; i < lin; i++)
		free(mat2[i]);

	// libera o vetor de ponteiros
	free(mat2); 
    
    
    return 0;
}