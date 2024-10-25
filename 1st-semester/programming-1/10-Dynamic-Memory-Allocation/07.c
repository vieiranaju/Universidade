#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Livro {
    char nome[50];
    char codigo[50];
    char autor[50];
    char assunto[50];
};

void adicionarLivro(struct Livro **livros, int *totallivros) {
    printf("\n__________________________________");

    *livros = (struct Livro *)realloc(*livros, (*totallivros + 1) * sizeof(struct Livro));

    setbuf(stdin, NULL);
    printf("\n-> Insira o Nome: \n");
    fgets((*livros)[*totallivros].nome, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira o Codigo: \n");
    fgets((*livros)[*totallivros].codigo, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira o Nome do Autor: \n");
    fgets((*livros)[*totallivros].autor, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira o Assunto: \n");
    fgets((*livros)[*totallivros].assunto, 50, stdin);

    (*totallivros)++;
}

void exibirLivros(struct Livro *livros, int totallivros) {
    printf("\nLivros cadastrados:\n");
    for (int i = 0; i < totallivros; i++) {
        printf("\n------------------------------------------");
        printf("\n- Nome: %s", livros[i].nome);
        printf("\n- Codigo: %s", livros[i].codigo);
        printf("\n- Autor: %s", livros[i].autor);
        printf("\n- Assunto: %s", livros[i].assunto);
    }
}

int verificarLivro(struct Livro *livros, int totallivros, char codigoB[]) {
    for (int i = 0; i < totallivros; i++) {
        if (strcmp(livros[i].codigo, codigoB) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int opcao, totallivros = 0;
    char codigoB[50];
    struct Livro *livros = NULL;

    do {
        printf("\nSelecione a opcao:\n");
        printf("1. Adicionar livro\n");
        printf("2. Exibir livros cadastrados\n");
        printf("3. Verificar livro\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        setbuf(stdin, NULL); 

        switch (opcao) {
            case 1:
                adicionarLivro(&livros, &totallivros);
                break;
            case 2:
                exibirLivros(livros, totallivros);
                break;
            case 3:
                printf("\nDigite o codigo do livro que deseja verificar: ");
                fgets(codigoB, 50, stdin);
                int h = verificarLivro(livros, totallivros, codigoB);
                if (h == 1) {
                    printf("\n-> O livro foi cadastrado!");
                } else {
                    printf("\n-> O livro nao foi cadastrado, codigo invalido!");
                }
                break;
            case 0:
                printf("\nEncerrando o programa.");
                break;
            default:
                printf("\nOpcao invalida.");
        }
    } while (opcao != 0);

    free(livros);
    return 0;
}
