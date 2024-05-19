// Implemente um programa que leia uma matriz de inteiros alocada dinamicamente, em que o número de 
// linhas e o número de colunas são determinados pelo usuário. Verifique quais elementos da matriz 
// são ímpares e múltiplos de 7. Em seguida, armazene os elementos identificados em um vetor, 
// também alocado dinamicamente, e os mostre na tela.
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// declaração de variável ponteiro para ponteiro
	int **mat, lin, col;

    printf("\nDigite o numero de linhas da matriz: \n");
    scanf("%d", &lin);

    printf("\nDigite o numero de colunas da matriz:\n");
    scanf("%d", &col);

	// alocando o vetor de ponteiros
	mat = (int**)malloc(lin * sizeof(int*));

	// alocando cada uma das linhas da matriz
	int i;
	for(i = 0; i < lin; i++)
		mat[i] = (int*)malloc(col * sizeof(int));

	int j;

	// preenchendo a matriz
	for(i = 0; i < lin; i++){

		for(j = 0; j < col; j++){

            printf("\nNumero [%d %d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);

        }
	}

    int *vet = NULL;

    int h = 0;

	// mostrando os elementos da matriz
	for(i = 0; i < lin; i++)
	{
		for(j = 0; j < col; j++)
			if (mat[i][j] % 2 != 0 && mat[i][j] %7 == 0){

                vet = (int *)realloc(vet, (h + 1) * sizeof(int));
                vet[h] = mat[i][j];
                h++;

            }
	}

    printf("\nSao impares e multiplos de 7 os numeros:\n");

    for(i = 0; i < h; i++){
        printf("\n%d ", vet[i]);
    }
    

	// libera cada linha
	for(i = 0; i < lin; i++)
		free(mat[i]);

	// libera o vetor de ponteiros
	free(mat);
    free(vet);

	return 0;
}