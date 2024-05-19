#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {

	int matricula;
	char nome[50];
	
}; 


int main() {

        struct aluno *alunos;
    
    alunos = (struct aluno *) malloc(20 * sizeof(struct aluno));
    alunos -> matricula = 1010101;
    strucpy(alunos -> nome, "Fulano");

    printf("Matricula = %d Nome = %s", alunos -> matricula, alunos -> nome);
    free(alunos);

    
    return 0;
}