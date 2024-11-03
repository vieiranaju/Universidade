#include "eleicoes.h"

int main() {
    int numEleitores, numChapas, i = 0, op;
    int numCandidato, dataNascimento[3];
    char nome[50], nomeVice[50];

    Arvore* arvChapas = CriaArvore();

    printf("Quantos eleitores deseja cadastrar? ");
    scanf("%d", &numEleitores);

    printf("Quantas chapas deseja cadastrar? ");
    scanf("%d", &numChapas);

    do {
        printf("Cadastrando chapa %d\n", i + 1);

        printf("Nome do candidato: ");
        scanf(" %[^\n]", nome);

        do{
        printf("Numero do candidato: ");
        scanf("%d", &numCandidato);
        } while(numCandidato>99 || numCandidato<1);

        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &dataNascimento[0], &dataNascimento[1], &dataNascimento[2]);

        printf("Nome do vice: ");
        scanf(" %[^\n]", nomeVice);

        Chapa* novaChapa = CriaChapa(nome, numCandidato, dataNascimento, nomeVice);
        arvChapas = InsereArvoreChapa(arvChapas, novaChapa);

        i++;
        system("cls");

        if (i < numChapas) {
            printf("Deseja continuar?\n");
            printf("1 - Sim\n2 - Nao\n");
            scanf("%d", &op);

            if (op == 2) {
                break;
            } else if (op != 1) {
                printf("Opção inválida!\n");
            }
        }

    } while (i < numChapas);

    if(i > 1){
        FILE* arquivoPrimeiroTurno = fopen("resultado_primeiro_turno.txt", "w");
    if (arquivoPrimeiroTurno == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    Votacao(arvChapas, numEleitores, arquivoPrimeiroTurno);

    if (VerificaSegundoTurno(arvChapas, numEleitores)) {
        Chapa* primeiro = NULL;
        Chapa* segundo = NULL;
        EncontraDoisMaisVotados(arvChapas, &primeiro, &segundo);
        arvChapas = AtualizaChapasSegundoTurno(arvChapas, primeiro, segundo);

        printf("\nHavera segundo turno!\n");

        FILE* arquivoSegundoTurno = fopen("resultado_segundo_turno.txt", "w");
        if (arquivoSegundoTurno == NULL) {
            printf("Erro ao abrir o arquivo resultado_segundo_turno.txt\n");
            return 1;
        }

        Votacao(arvChapas, numEleitores, arquivoSegundoTurno);

        fclose(arquivoSegundoTurno);
    }

    fclose(arquivoPrimeiroTurno);
    }

    EsvaziarArvore(arvChapas);

    return 0;
}
