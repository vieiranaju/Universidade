// Implemente um programa que leia os códigos de matrícula dos alunos de duas disciplinas 
// (progI e progII) e mostre os códigos de matrícula dos alunos que estão cursando ambas as disciplinas. 
// O número de alunos de ambas as turmas é informado pelo usuário. O espaço de memória necessário para 
// armazenar os códigos das matrículas nas disciplinas deve ser criado dinamicamente, de acordo com 
// esse número.
#include <stdio.h>
#include <stdlib.h>

void verifica(int* vetX, int* vetY, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (vetX[i] == vetY[j])

            printf("\nO aluno %d esta em ambas as turmas", vetX[i]);

        }
    }
    
}

int main() {

    int n, m;

    printf("\nQual o tamanho a quantia de alunos na turma de programacao I?\n");
    scanf("%d", &n);

    printf("\nQual o tamanho a quantia de alunos na turma de programacao II?\n");
    scanf("%d", &m);

    int* progI = (int*)malloc(n * sizeof(int));

    int* progII = (int*)malloc(m * sizeof(int));

    if(progI == NULL || progII == NULL){
        printf("Erro: memória insuficiente !");
        exit(1);
    }
    
    printf("\n->Preencha os codigos de matricula da turma de programacao I");

    for (int i = 0; i < n; i++) {

        printf("\nAluno(a) %d:  ", i+1);
        scanf("%d", &progI[i]);

    }

    printf("\n->Preencha os codigos de matricula da turma de programacao I");

    for (int i = 0; i < m; i++) {

        printf("\nAluno(a) %d:  ", i+1);
        scanf("%d", &progII[i]);

    }

    
    verifica(progI, progII, n, m);


    free(progI); 
    free(progII); 
    
    return 0;
}