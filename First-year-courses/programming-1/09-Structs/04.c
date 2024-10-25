#include <stdio.h>

struct RPG {

	char nome[20];
    int ID, Level, Vida, Ataque, Defesa;

}; 


int main() {
        
        int n;
    
    printf("\nQuantos personagens/monstros deseja cadastrar? ");
    scanf("%d", &n);

    struct RPG C[n];

    for (int i = 0; i < n; i++) {

        printf("\n_________________Personagem/Monstro %d_________________", i + 1);
        printf("\n-> Insira o ID:\n");  
        scanf("%d", &C[i].ID);

        setbuf(stdin, NULL);
        printf("\n->Insira o Nome ( ate 20 caracteres! ):\n");
        fgets(C[i].nome, 20, stdin);

        printf("\n-> Insira o Level:\n");  
        scanf("%d", &C[i].Level);

        printf("\n-> Insira o total de Vida:\n");  
        scanf("%d", &C[i].Vida);

        printf("\n-> Insira o total de Ataque:\n");  
        scanf("%d", &C[i].Ataque);

        printf("\n-> Insira o total de Defesa:\n");  
        scanf("%d", &C[i].Defesa);
        }

    for (int i = 0; i < n; i++) {
        printf("\n-------------------------------------");
        printf("\n-------Personagem/Monstro %d---------\n", i + 1);
        printf("- Id: %d", C[i].ID);
        printf("\n- Nome: %s", C[i].nome);
        printf("- Level: %d", C[i].Level);
        printf("\n- Vida: %d", C[i].Vida);
        printf("\n- Ataque: %d", C[i].Ataque);
        printf("\n- Defesa: %d", C[i].Defesa);
    }


    return 0;
}