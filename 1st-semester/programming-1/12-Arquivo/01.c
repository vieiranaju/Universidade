#include <stdio.h>

#define MAX 100

int main() {

    FILE *file = fopen("livros.txt", "w");

    if (file == NULL) {
        printf("Erro.\n");
        return 1;
    }

    int n;
    printf("Quantos livros?");
    scanf("%d", &n);
    getchar();

    if (n < 1) {
        printf("Valor invalido.\n");
        return 1;
    }

    char titulos[n][50];
    int registros[n];
    double precos[n];

    for (int i = 0; i < n; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Digite o titulo do livro: ");
        fgets(titulos[i], 50, stdin);
        printf("Digite o numero de registro do livro: ");
        scanf("%d", &registros[i]);
        printf("Digite o preço do livro: ");
        scanf("%lf", &precos[i]);
        getchar();

        fprintf(file, "%s\n%d\n%.2f\n", titulos[i], registros[i], precos[i]);
    }

    fclose(file);

    file = fopen("livros.txt", "r");
    if (file == NULL) {
        printf("Erro\n");
        return 1;
    }

    printf("\nLivros armazenados:\n");
    for (int i = 0; i < n; i++) {
        printf("\nLivro %d:\n", i + 1);
        fscanf(file, "%s", titulos[i]);
        fscanf(file, "%d", &registros[i]);
        fscanf(file, "%lf", &precos[i]);
        printf("Titulo: %s", titulos[i]);
        printf("Registro: %d\n", registros[i]);
        printf("Preço: %.2f\n", precos[i]);
    }

    fclose(file);

    return 0;
}
