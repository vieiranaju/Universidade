#include <stdio.h>
#include <stdlib.h> 

struct Cadastro {
    char nome[50];
    char nomeDono[50];
    char especie[50];
    char sintoma[200];
    char diagnostico[200];
    int ID;
    int idade;
};

void preencherCadastro(struct Cadastro *cadastros, int x) {

    system("cls");

    setbuf(stdin, NULL);
    printf("Insira o nome do animal: ");
    fgets(cadastros[x].nome, 50, stdin);
    setbuf(stdin, NULL);
    printf("Insira o nome do dono: ");
    fgets(cadastros[x].nomeDono, 50, stdin);
    setbuf(stdin, NULL);
    printf("Insira a especie: ");
    fgets(cadastros[x].especie, 50, stdin);
    printf("Insira os Sintomas: ");
    fgets(cadastros[x].sintoma, 200, stdin);
    printf("Insira o diagnostico: ");
    fgets(cadastros[x].diagnostico, 200, stdin);
    setbuf(stdin, NULL);
    printf("Insira a idade: ");
    scanf("%d", &cadastros[x].idade);
    cadastros[x].ID = x + 1;
    printf("\n=========================================");

    FILE *arq = fopen("cadastros.txt", "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(arq, "%s %s %s %s %s %d %d\n", cadastros[x].nome, cadastros[x].nomeDono, cadastros[x].sintoma, cadastros[x].especie, cadastros[x].diagnostico, cadastros[x].ID, cadastros[x].idade);
    
    fclose(arq);
    
}

void visualizarCadastros() {

    system("cls");

    FILE *arq = fopen("cadastros.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Cadastros armazenados:\n");
    struct Cadastro animal;

    while (fscanf(arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma, animal.diagnostico, &animal.ID, &animal.idade) != EOF) {
        printf("\n=========================================\n");
        printf("\n- Nome: %s", animal.nome);
        printf("\n- Nome do responsavel: %s", animal.nomeDono);
        printf("\n- Especie: %s", animal.especie);
        printf("\n- Sintomas: %s", animal.sintoma);
        printf("\n- Diagnostico: %s", animal.diagnostico);
        printf("\n- ID: %d\n ", animal.ID);
        printf("- Idade: %d\n ", animal.idade);
        printf("\n=========================================\n");
    }
    
    fclose(arq);
}

void modificarCadastros(int id) {

    FILE *arq = fopen("cadastros.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp_arq = fopen("temp_cadastros.txt", "w");
    if (temp_arq == NULL) {
        printf("Erro ao abrir o arquivo temporario.\n");
        fclose(arq);
        return;
    }

    struct Cadastro animal;
    int encontrado = 0;

    while (fscanf(arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma,  animal.diagnostico, &animal.ID, &animal.idade) != EOF) {
        if (animal.ID == id) {
            printf("\nModificando cadastro de ID %d\n", id);
            printf("\nInsira o nome do animal: ");
            scanf("%s", animal.nome);
            printf("Insira o nome do dono: ");
            scanf("%s", animal.nomeDono);
            printf("Insira a especie: ");
            scanf("%s", animal.especie);
            printf("Insira os Sintomas: ");
            scanf("%s", animal.sintoma);
            printf("Insira o diagnostico: ");
            scanf("%s", animal.diagnostico);
            printf("Insira a idade: ");
            scanf("%d", &animal.idade);
            encontrado = 1;
        }
        fprintf(temp_arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma, animal.diagnostico, animal.ID, animal.idade);
    }

    fclose(arq);
    fclose(temp_arq);

    remove("cadastros.txt");
    rename("temp_cadastros.txt", "cadastros.txt");

    if (!encontrado) {
        printf("ID do cadastro nao encontrado.\n");
    } else {
        printf("\nCadastro modificado com sucesso.\n");
    }
}

void deletarCadastros(int id) {

    FILE *arq = fopen("cadastros.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp_arq = fopen("temp_cadastros.txt", "w");
    if (temp_arq == NULL) {
        printf("Erro ao abrir o arquivo temporario.\n");
        fclose(arq);
        return;
    }

    struct Cadastro animal;
    int encontrado = 0;

    while (fscanf(arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma, animal.diagnostico, &animal.ID, &animal.idade) != EOF) {
        if (animal.ID == id) {
            encontrado = 1;
        } else {
            fprintf(temp_arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma, animal.diagnostico, animal.ID, animal.idade);
        }
    }

    fclose(arq);
    fclose(temp_arq);

    remove("cadastros.txt");
    rename("temp_cadastros.txt", "cadastros.txt");

    if (!encontrado) {
        printf("ID do cadastro nao encontrado.\n");
    } else {
        printf("\nCadastro deletado com sucesso.\n");
    }
}

void visualizarAnimalPorId(int id) {

    FILE *arq = fopen("cadastros.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct Cadastro animal;
    int encontrado = 0;

    while (fscanf(arq, "%s %s %s %s %s %d %d\n", animal.nome, animal.nomeDono, animal.especie, animal.sintoma, animal.diagnostico, &animal.ID, &animal.idade) != EOF) {
        if (animal.ID == id) {
            printf("\n=========================================\n");
            printf("\n- Nome: %s", animal.nome);
            printf("\n- Nome do responsavel: %s", animal.nomeDono);
            printf("\n- Especie: %s", animal.especie);
            printf("\n- Sintomas: %s", animal.sintoma);
            printf("\n- Diagnostico: %s", animal.diagnostico);
            printf("\n- ID: %d ", animal.ID);
            printf("\n- Idade: %d\n\n ", animal.idade);
            printf("\n=========================================\n");
            encontrado = 1;
            break;
        }
    }

    fclose(arq);

    if (!encontrado) {
        printf("Animal com ID %d nao encontrado.\n", id);
    }
}


int main() {

    int op = 0, i = 0, n;
    struct Cadastro *cadastros = NULL;

    while (op != 6) {
        
        printf("\n=========================================\n");
        printf("Opcao [1] = Cadastrar ! ");
        printf("\nOpcao [2] = Visualizar cadastros ! ");
        printf("\nOpcao [3] = Deletar ! ");
        printf("\nOpcao [4] = Modificar Cadastro ! ");
        printf("\nOpcao [5] = Consultar Cadastro ! ");
        printf("\nOpcao [6] = Fechar ! ");
        printf("\n=========================================\n");

        if(op != 6 ){

            scanf("%d", &op);

            switch (op) {
                case 1:
                    i++;
                    cadastros = (struct Cadastro *)realloc(cadastros, i * sizeof(struct Cadastro));
                    printf("\n===========Cadastro numero %d=============\n", i);
                    preencherCadastro(cadastros, i - 1);
                    break;

                case 2:
                    visualizarCadastros();
                    break;

                case 3:
                    printf("\nInsira o ID do cadastro que deseja deletar:\n");
                    scanf("%d", &n);
                    deletarCadastros(n);
                    break;

                case 4:
                    printf("\nInsira o ID do cadastro que deseja modificar:\n");
                    scanf("%d", &n);
                    modificarCadastros(n);
                    break;
                case 5:
                    printf("Insira qual registro voce quer consultar: ");
                    scanf("%d", &n);
                    visualizarAnimalPorId(n);
                    break;

                default:
                    break;
            }
        }
    }

    printf("Adeus!");

    
    free(cadastros);
    
    return 0;
}
