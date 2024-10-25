#include <stdio.h>

struct Livro {
    char titulo[50];
    int registro;
    float preco;
};

void preencherLivro(struct Livro *livro) {
    setbuf(stdin, NULL);
    printf("Digite o título do livro: ");
    fgets(livro->titulo, 50, stdin);
    printf("Digite o número de registro do livro: ");
    scanf("%d", &livro->registro);
    getchar();
    setbuf(stdin, NULL);
    printf("Digite o preço do livro: ");
    scanf("%f", &livro->preco);
}

void escreverLivro(struct Livro *livro) {
    FILE *fp = fopen("livros.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(fp, "%s %d %.2f\n", livro->titulo, livro->registro, livro->preco);
    fclose(fp);
}

void lerLivros() {
    FILE *fp = fopen("livros.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct Livro livro;

    printf("Livros armazenados:\n");
    while (fscanf(fp, "%49s %d %f", livro.titulo, &livro.registro, &livro.preco) != EOF) {
        printf("Título: %s, Registro: %d, Preço: %.2f\n", livro.titulo, livro.registro, livro.preco);
    }

    fclose(fp);
}

int main() {
    
    int n;

    printf("Quantos Livros?");
    scanf("%d", &n);
    getchar();

    struct Livro livro[n];

    for (int i = 0; i < n; i++) {
        preencherLivro(&livro[i]);
        escreverLivro(&livro[i]);
    }

    lerLivros();
    return 0;
}