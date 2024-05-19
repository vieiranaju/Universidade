#include <stdio.h>
#define MAX 50

struct alunos {

	char nome[MAX];
	int idade;
    float altura, peso;

}; 


int main() {

        struct alunos C[20];
        float novo = 100, Mpeso = 0;
        int num, num2;

    for (int i = 0; i < 20; i++) {
        printf("\n_________________Aluno %d_________________", i + 1);

        setbuf(stdin, NULL);
        printf("\n-> Insira o Nome: \n");
        fgets(C[i].nome, MAX, stdin);

        printf("\n-> Insira a idade:\n");  
        scanf("%d", &C[i].idade);

        printf("\n-> Insira a Altura:\n");  
        scanf("%f", &C[i].altura);

        printf("\n-> Insira o peso:\n");  
        scanf("%f", &C[i].peso);
        }

    for (int i = 0; i < 20; i++) {

        if(C[i].peso > Mpeso){
            Mpeso = C[i].peso;
            num = i;
            }

        if(C[i].idade < novo){
            novo = C[i].idade;
            num2 = i;
        }
        
    }

    printf("\n---Aluno %d -> Mais novo---", num2 + 1);
    printf("\nNome: %s", C[num2].nome); 
    printf("Idade: %d", C[num2].idade);
    printf("\nAltura: %.1f", C[num2].altura);
    printf("\nPeso: %.1f\n", C[num2].peso);

    printf("\n---Aluno %d -> Maior peso---", num + 1);
    printf("\nNome: %s", C[num].nome); 
    printf("Idade: %d", C[num].idade);
    printf("\nAltura: %.1f", C[num].altura);
    printf("\nPeso: %.1f", C[num].peso);

    return 0;
}