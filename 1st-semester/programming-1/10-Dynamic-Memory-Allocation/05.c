#include <stdio.h>
#include <stdlib.h>

int buscaNumero(int numero, int **array, int linha, int coluna) {

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++){

            if(array[i][j] == numero){
                return 1;
            }
    
    }
}

return 0;
    
}

int main() {

    int **mat, lin, col;

    printf("\nDigite o numero de linhas da matriz: \n");
    scanf("%d", &lin);

    printf("\nDigite o numero de colunas da matriz:\n");
    scanf("%d", &col);

	// alocando o vetor de ponteiros
	mat = (int**)malloc(lin * sizeof(int*));


    int i, j;

	// alocando cada uma das linhas da matriz
	for(i = 0; i < lin; i++)
		mat[i] = (int*)malloc(col * sizeof(int));


    if(mat == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }

	// preenchendo a matriz
	for(i = 0; i < lin; i++){

		for(j = 0; j < col; j++){

            printf("\nNumero [%d %d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);

        }
	}

    int x;

    printf("\nDigite o numero que deseja verificar na matriz:\n");
    scanf("%d", &x);

    
    int resultado = buscaNumero(x, mat, lin, col);

    if(resultado == 1){
        printf("\nO numero %d se encontra na matriz !\n", x);
    }

    else{

        printf("\nO numero %d nao se encontra na matriz !\n", x);
    }

    // libera cada linha
	for(i = 0; i < lin; i++)
		free(mat[i]);

	// libera o vetor de ponteiros
	free(mat); 
    
    return 0;
}