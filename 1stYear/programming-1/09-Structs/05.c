#include <stdio.h>
#define MAX 50

struct cadastro {

	int matricula;
	char nome[MAX];
	float nota;

}; 


int main() {

        struct cadastro C[MAX];
        float maior = 0;
        int num;

    for (int i = 0; i < MAX; i++) {
        printf("\n_________________Aluno %d_________________", i + 1);
        printf("\n-> Insira o numero de matricula\n");  
        scanf("%d", &C[i].matricula);

        setbuf(stdin, NULL);
        printf("-> Insira o Nome: \n");
        fgets(C[i].nome, 50, stdin);

        printf("\n-> Insira a Nota:\n");  
        scanf("%f", &C[i].nota);
        }

    for (int i = 0; i < MAX; i++) {
        printf("\n---Aluno %d---", i + 1);
        printf("\nNome: %s", C[i].nome); 
        printf("\nNumero de matricula: %d", C[i].matricula);
        printf("\nNota: %.1f", C[i].nota);

        if(C[i].nota >= 7){
            printf("\nAprovado!\n");
        }
        else if(C[i].nota >= 4){
            printf("\nExame!\n");
        }
        else{
            printf("\nReprovado!\n");
        }

        if(C[i].nota > maior){
            maior = C[i].nota;
            num = i;
        }
        
    }

    printf("\nA maior nota foi %.1f do aluno %d", maior, num + 1);


    return 0;
}