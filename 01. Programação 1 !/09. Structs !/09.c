#include <stdio.h>
#include <string.h>
#define MAX 100

struct Jogo {

	char nome[50];
    char genero[50];
    char modoJogo[50];
    char plataforma[50];
    int ranking;

};

void adicionarJogo(struct Jogo jogos[], int *totalJogos){

    printf("\n__________________________________");

    setbuf(stdin, NULL);
    printf("\n-> Insira o Nome: \n");
    fgets(jogos[*totalJogos].nome, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira o Genero: \n");
    fgets(jogos[*totalJogos].genero, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira o Modo de Jogo: \n");
    fgets(jogos[*totalJogos].modoJogo, 50, stdin);

    setbuf(stdin, NULL);
    printf("\n-> Insira a plataforma: \n");
    fgets(jogos[*totalJogos].plataforma, 50, stdin);

    printf("\n-> Insira o Ranking:\n");  
    scanf("%d", &jogos[*totalJogos].ranking);

    (*totalJogos)++;


}

void exibirJogos(struct Jogo jogos[], int totalJogos){
    printf("\nJogos cadastrados:\n");

    for (int i = 0; i < totalJogos; i++) {
        printf("\n------------------------------------------");
        printf("\n- Nome: %s", jogos[i].nome);
        printf("\n- Genero: %s", jogos[i].genero);
        printf("\n- Modo de Jogo: %s", jogos[i].modoJogo);
        printf("\n- Plataforma: %s", jogos[i].plataforma);
        printf("\n- Ranking: %d\n ", jogos[i].ranking);
    }
}

void buscaPorGenero(struct Jogo jogos[], int totalJogos, char generoB[]){
    int j = 0;

     for (int i = 0; i < totalJogos; i++) {

        if(strcmp(jogos[i].genero, generoB)){

            printf("\n------------------------------------------");
            printf("\n- Nome: %s", jogos[i].nome);
            printf("\n- Genero: %s", jogos[i].genero);
            printf("\n- Modo de Jogo: %s", jogos[i].modoJogo);
            printf("\n- Plataforma: %s", jogos[i].plataforma);
            printf("\n- Ranking: %d\n ", jogos[i].ranking);
            j++;

        }

     }

     if(j == 0){
        printf("Nenhum jogo coincide com o genero buscado !");
     }

}

void JogoPorRanking(struct Jogo jogos[], int totalJogos, int rankingB){

    int j = 0;

    for (int i = 0; i < totalJogos; i++) {

        if(jogos[i].ranking == rankingB){

            printf("\n------------------------------------------");
            printf("\n- Nome: %s", jogos[i].nome);
            printf("\n- Genero: %s", jogos[i].genero);
            printf("\n- Modo de Jogo: %s", jogos[i].modoJogo);
            printf("\n- Plataforma: %s", jogos[i].plataforma);
            printf("\n- Ranking: %d\n ", jogos[i].ranking);

            j++;

        }
    }
    if(j == 0){
        printf("Nenhum jogo coincide com o ranking buscado !");
     }

}

void verificarFavorito(struct Jogo jogos[], int totalJogos, char jogoF[]){

    int j = 0;

    for (int i = 0; i < totalJogos; i++) {

        if(strcmp(jogos[i].genero, jogoF)){

            if(jogos[i].ranking == 5){

            printf("\n------------------------------------------");
            printf("\n- Nome: %s", jogos[i].nome);
            printf("\n- Genero: %s", jogos[i].genero);
            printf("\n- Modo de Jogo: %s", jogos[i].modoJogo);
            printf("\n- Plataforma: %s", jogos[i].plataforma);
            printf("\n- Ranking: %d\n ", jogos[i].ranking);
            break;
            }

            j++;


        }

     }

     if(j == 0){

        printf("Este jogo não foi adicionado! ");
     }

}



int main(){

    struct Jogo jogos[MAX];
    int opcao, totalJogos = 0;
    char generoB[20], jogoF[50];
    int rankingB;

    do {
        printf("\nSelecione a opcao:\n");
        printf("1. Adicionar jogo\n");
        printf("2. Exibir jogos cadastrados\n");
        printf("3. Busca por genero\n");
        printf("4. Exibir jogo por ranking\n");
        printf("5. Verificar se jogo é favorito\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarJogo(jogos, &totalJogos);
                break;
            case 2:
                exibirJogos(jogos, totalJogos);
                break;
            case 3:
                printf("\nDigite o genero que deseja buscar: ");
                scanf("%s", generoB);
                buscaPorGenero(jogos, totalJogos, generoB);
                break;
            case 4:
                printf("\nDigite o ranking que deseja buscar: ");
                scanf("%d", &rankingB);
                JogoPorRanking(jogos, totalJogos, rankingB);
                break;
            case 5:
                printf("\nDigite o nome do jogo que deseja verificar: ");
                scanf("%s", jogoF);
                verificarFavorito(jogos, totalJogos, jogoF);
                break;
            case 0:
                printf("\nEncerrando o programa.");
                break;
            default:
                printf("\nOpcao invalida.");
        }
    } while (opcao != 0);

    return 0;
}