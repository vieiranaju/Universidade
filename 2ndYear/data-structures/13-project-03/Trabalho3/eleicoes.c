#include "eleicoes.h"

struct chapa {
    char nomeCandidato[50];
    int numero;
    int dataNascimento[3];
    char nomeVice[50];
    int votos;
};

struct arvore {
    Chapa* c;
    Arvore* esquerda;
    Arvore* direita;
};

struct categoriaVotos {
    int validos;
    int nulos;
    int brancos;
};

Arvore* CriaArvore() {
    return NULL;
}

int ArvoreVazia(Arvore* arv) {
    return arv == NULL;
}

Chapa* CriaChapa(char* nomeCandidato, int numero, int* dataNascimento, char* nomeVice) {
    Chapa* novaChapa = (Chapa*)malloc(sizeof(Chapa));

    if (novaChapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    strcpy(novaChapa->nomeCandidato, nomeCandidato);
    novaChapa->numero = numero;
    novaChapa->dataNascimento[0] = dataNascimento[0];
    novaChapa->dataNascimento[1] = dataNascimento[1];
    novaChapa->dataNascimento[2] = dataNascimento[2];
    strcpy(novaChapa->nomeVice, nomeVice);
    novaChapa->votos = 0;

    return novaChapa;
}

Arvore* InsereArvoreChapa(Arvore* arvChapas, Chapa* novaChapa) {
    if (arvChapas == NULL) {
        Arvore* novaArv = (Arvore*)malloc(sizeof(Arvore));
        if (novaArv == NULL) exit(1);

        novaArv->c = novaChapa;
        novaArv->esquerda = NULL;
        novaArv->direita = NULL;

        return novaArv;
    } else if (arvChapas->c->numero > novaChapa->numero) {
        arvChapas->esquerda = InsereArvoreChapa(arvChapas->esquerda, novaChapa);
    } else {
        arvChapas->direita = InsereArvoreChapa(arvChapas->direita, novaChapa);
    }

    return arvChapas;
}

void ImprimeArvoreChapas(Arvore* arvoreChapas) {
    if (arvoreChapas != NULL) {
        ImprimeArvoreChapas(arvoreChapas->esquerda);
        printf("Candidato: %s\n", arvoreChapas->c->nomeCandidato);
        printf("Numero: %d\n", arvoreChapas->c->numero);
        printf("-------------------------------\n");
        ImprimeArvoreChapas(arvoreChapas->direita);
    }
}

categoriaVotos* Votar(Arvore* arvChapas, int numero, categoriaVotos* tipoVotos) {
    if (arvChapas == NULL) {
        printf("Seu voto em branco foi confirmado!\n");
        tipoVotos->brancos++;
        return tipoVotos;
    } else if (numero == 0) {
        printf("Seu voto nulo foi confirmado!\n");
        tipoVotos->nulos++;
        return tipoVotos;
    }
    if (arvChapas->c->numero == numero) {
        printf("Seu voto em %s com vice %s foi confirmado!\n", arvChapas->c->nomeCandidato, arvChapas->c->nomeVice);
        arvChapas->c->votos++;
        tipoVotos->validos++;
        return tipoVotos;
    } else if (numero < arvChapas->c->numero) {
        return Votar(arvChapas->esquerda, numero, tipoVotos);
    } else {
        return Votar(arvChapas->direita, numero, tipoVotos);
    }
}

int VerificaSegundoTurno(Arvore* arvoreChapas, int totalPopulacao) {
    Chapa* primeiro = NULL;
    Chapa* segundo = NULL;
    int totalChapas = ContarTotalChapas(arvoreChapas);

    if (totalChapas <= 2) {
        return 0;
    }

    EncontraDoisMaisVotados(arvoreChapas, &primeiro, &segundo);

    if (primeiro && segundo && totalPopulacao > 10) {
        float percVotosPrimeiro = (float)primeiro->votos / totalPopulacao * 100;

        if (percVotosPrimeiro < 50) {
            return 1;
        }
    }
    return 0;
}


int ContarTotalChapas(Arvore* arvoreChapas) {
    if (arvoreChapas == NULL) {
        return 0;
    }
    return 1 + ContarTotalChapas(arvoreChapas->esquerda) + ContarTotalChapas(arvoreChapas->direita);
}


void ImprimeArvoreCandidatos(FILE* arquivoTurno, Arvore* arvoreChapas, int totalEleitores, Chapa** candidatoVencedor) {
    if (arvoreChapas != NULL) {
        ImprimeArvoreCandidatos(arquivoTurno, arvoreChapas->esquerda, totalEleitores, candidatoVencedor);
        float percVotos = (float)arvoreChapas->c->votos / totalEleitores * 100;
        fprintf(arquivoTurno, "%s %d %d %d/%d/%d (%.2f%% dos votos)\n",
                arvoreChapas->c->nomeCandidato,
                arvoreChapas->c->numero,
                arvoreChapas->c->votos,
                arvoreChapas->c->dataNascimento[0],
                arvoreChapas->c->dataNascimento[1],
                arvoreChapas->c->dataNascimento[2],
                percVotos);

        if (*candidatoVencedor == NULL || arvoreChapas->c->votos > (*candidatoVencedor)->votos) {
            *candidatoVencedor = arvoreChapas->c;
        }

        ImprimeArvoreCandidatos(arquivoTurno, arvoreChapas->direita, totalEleitores, candidatoVencedor);
    }
}

void ImprimeBoletim(Arvore* arvoreChapas, FILE* arquivoTurno, categoriaVotos* tipoVotos, int totalEleitores) {
    float percValidos = (float)tipoVotos->validos / totalEleitores * 100;
    float percTotais = (float)(tipoVotos->validos + tipoVotos->brancos + tipoVotos->nulos) / totalEleitores * 100;
    float percBrancos = (float)tipoVotos->brancos / totalEleitores * 100;
    float percNulos = (float)tipoVotos->nulos / totalEleitores * 100;

    fprintf(arquivoTurno, "=== Boletim de Urna ===\n\n");
    Chapa* candidatoVencedor = NULL;
    ImprimeArvoreCandidatos(arquivoTurno, arvoreChapas, totalEleitores, &candidatoVencedor);

    fprintf(arquivoTurno, "Votos brancos: %d (%.2f%% dos votos totais)\n", tipoVotos->brancos, percBrancos);
    fprintf(arquivoTurno, "Votos nulos: %d (%.2f%% dos votos totais)\n", tipoVotos->nulos, percNulos);
    fprintf(arquivoTurno, "Votos validos: %d (%.2f%% dos votos totais)\n", tipoVotos->validos, percValidos);
    fprintf(arquivoTurno, "Total de votos computados: %.2f%% dos eleitores\n\n", percTotais);

    if (VerificaSegundoTurno(arvoreChapas, totalEleitores)) {
        fprintf(arquivoTurno, "Haverá segundo turno!\n");
    } else {
        if (candidatoVencedor) {
            fprintf(arquivoTurno, "O candidato %s venceu com %d votos (%.2f%%).\n",
                    candidatoVencedor->nomeCandidato,
                    candidatoVencedor->votos,
                    (float)candidatoVencedor->votos / totalEleitores * 100);
        }
    }
}

void EncontraDoisMaisVotados(Arvore* arvoreChapas, Chapa** primeiro, Chapa** segundo) {
    if (arvoreChapas != NULL) {
        EncontraDoisMaisVotados(arvoreChapas->esquerda, primeiro, segundo);

        if (*primeiro == NULL || arvoreChapas->c->votos > (*primeiro)->votos) {
            *segundo = *primeiro;
            *primeiro = arvoreChapas->c;
        } else if (*segundo == NULL || arvoreChapas->c->votos > (*segundo)->votos) {
            *segundo = arvoreChapas->c;
        }

        EncontraDoisMaisVotados(arvoreChapas->direita, primeiro, segundo);
    }
}

Arvore* AtualizaChapasSegundoTurno(Arvore* arvChapas, Chapa* primeiro, Chapa* segundo) {

    primeiro->votos = 0;
    segundo->votos = 0;

    Arvore* novaArvChapas = CriaArvore();
    novaArvChapas = InsereArvoreChapa(novaArvChapas, primeiro);
    novaArvChapas = InsereArvoreChapa(novaArvChapas, segundo);

    return novaArvChapas;
}


int ComparaDataNascimento(int data1[3], int data2[3]) {
    if (data1[2] > data2[2]) return 1;
    if (data1[2] < data2[2]) return -1;
    if (data1[1] > data2[1]) return 1;
    if (data1[1] < data2[1]) return -1;
    if (data1[0] > data2[0]) return 1;
    if (data1[0] < data2[0]) return -1;
    return 0;
}

void Votacao(Arvore* arvChapas , int totalPopulacao, FILE* arquivoTurno){
    int i = 0, numCandidato;
    categoriaVotos* tipoVotos = malloc(sizeof(categoriaVotos));
    tipoVotos->validos = 0;
    tipoVotos->nulos = 0;
    tipoVotos->brancos = 0;

    do{

        printf("\n=== Candidatos Disponiveis ===\n\n");

        ImprimeArvoreChapas(arvChapas);

        printf("\nDigite o numero do candidato que voce deseja votar e pressione Enter: ");
        scanf("%d", &numCandidato);

        tipoVotos = Votar(arvChapas, numCandidato, tipoVotos);

        i++;
        system("cls");

    }while(i < totalPopulacao);

    ImprimeBoletim(arvChapas, arquivoTurno, tipoVotos, totalPopulacao);

    free(tipoVotos);
}

Arvore* EsvaziarArvore(Arvore* arvChapas) {
    if (arvChapas != NULL) {
        EsvaziarArvore(arvChapas->esquerda);
        EsvaziarArvore(arvChapas->direita);
        free(arvChapas->c);
        free(arvChapas);
    }
    return NULL;
}
