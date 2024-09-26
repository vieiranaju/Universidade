#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Alunos
{
    char nome[MAX], sobrenome[MAX];
    float nota;
};

void alunoMaiorNota(struct Alunos *vetAlunos, int tam){

    float maior = 0;
    int maiorPos;

    for(int i = 0; i<tam; i++){

        if(vetAlunos[i].nota > maior){


            maior = vetAlunos[i].nota;
            maiorPos = i;

        }

    }

    printf("\n====================================================");
    printf("\nA maior nota pertence ao aluno(a) %d", maiorPos + 1);
    printf("\nNome: %s", vetAlunos[maiorPos].nome);
    printf("\nSobreome: %s", vetAlunos[maiorPos].sobrenome);
    printf("\nNota: %.1f", vetAlunos[maiorPos].nota);


    free(vetAlunos);
}

int main(){

    int n;

    printf("\nInsira a Quantidade de Alunos que Deseja Cadastrar: \n");
    scanf("%d", &n);

    struct Alunos *Aluno = (struct Alunos *)malloc(n * sizeof(struct Alunos));


    printf("\n----------------------------------");
    printf("\nPreencha os dados dos alunos:\n");

    for(int i = 0; i < n; i++){

        printf("\nAluno(a) %d", i + 1);

        setbuf(stdin, NULL);
        printf("\nInsira o nome: \n");
        fgets(Aluno[i].nome, MAX, stdin);

        setbuf(stdin, NULL);
        printf("\nInsira o sobrenome: \n");
        fgets(Aluno[i].sobrenome, MAX, stdin);

        printf("\nInsira a nota: \n");
        scanf("%f", &Aluno[i].nota);
    }

    

    alunoMaiorNota(Aluno, n);

    

}