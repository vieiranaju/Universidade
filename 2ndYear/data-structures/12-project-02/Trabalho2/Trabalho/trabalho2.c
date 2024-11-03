#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

int main(){
    /*Abrindo os arquivos que serão utilizados e verificando se não ocorreram erros, caso haja algum problema, encerra o programa*/
    FILE *arq, *arq_saida;
    arq = fopen("entrada.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    arq_saida = fopen("saida.txt", "w");
    if(arq_saida == NULL){
        printf("Erro ao abrir o arquivo de saida!\n");
        /*Fecha o arquivo de entrada antes de encerrar o programa em caso de erros*/
        fclose(arq);
        return 1;
    }

    /*Cria e inicializa a lista*/
    Arvore* arv_medicamentos = CriaArvore();

    /*Variaveis Auxiliares*/
    char texto_str[40], nome[30];
    int codigo, data_validade[3];
    float valor;

    /*Continua lendo o arquivo e armazenando o comando na variavel 'texto_str' até chegar a uma linha vazia*/
    while(fscanf(arq, "%s", texto_str) != EOF){

        /*Verifica qual o comando armazenado em 'texto_str' e chama o comando correspondente*/
        if(strcmp(texto_str, "MEDICAMENTO") == 0){
            /*Para adicionar um novo medicamento é necessario ler todas as informações a serem adicionadas*/
            fscanf(arq, "%s %d %f %d %d %d", nome, &codigo, &valor, &data_validade[0], &data_validade[1], &data_validade[2]);
            /*Criando o medicamento*/
            Medicamento* NovoMedicamento = CriaMedicamento(nome, codigo, valor, data_validade);
            /*Adicionando na arvore*/
            arv_medicamentos = InsereArvoreMedicamento(arq_saida, arv_medicamentos, NovoMedicamento);

        } else if(strcmp(texto_str, "RETIRA") == 0){
            /*Lê o codigo do medicamento a ser retirado da lista e passa para a função*/
            fscanf(arq, "%d", &codigo);
            RetiraArvoreMedicamento(arq_saida, arv_medicamentos, codigo);

        } else if(strcmp(texto_str, "IMPRIME_ARVORE") == 0){
            /*Mostrar todos os medicamentos presentes na arvore*/
            ImprimeArvoreMedicamentos(arq_saida, arv_medicamentos);

        } else if(strcmp(texto_str, "ATUALIZA_PRECO") == 0){
            /*Lê o codigo do medicamento e o valor a ser atualizado*/
            fscanf(arq, "%d %f", &codigo, &valor);
            AtualizaPrecoMedicamento(arq_saida, arv_medicamentos, codigo, valor);

        } else if(strcmp(texto_str, "VERIFICA_VALIDADE") == 0){
            /*Lê a data atual e armazena no vetor para verificar se existem medicamentos vencidos*/
            fscanf(arq, "%d %d %d", &data_validade[0], &data_validade[1], &data_validade[2]);
            if(!VerificaArvoreValidade(arq_saida, arv_medicamentos, data_validade)){
                fprintf(arq_saida, "MEDICAMENTO VENCIDO NAO ENCONTRADO NA ARVORE\n");
            }

        } else if(strcmp(texto_str, "VERIFICA_ARVORE") == 0){
            /*Busca um medicamento por meio do ID lido*/
            fscanf(arq, "%d", &codigo);
            if (!VerificaArvoreMedicamento(arq_saida, arv_medicamentos, codigo)) {
            /* Se o medicamento não for encontrado, imprime a mensagem */
            fprintf(arq_saida, "MEDICAMENTO NAO ENCONTRADO NA ARVORE\n");
            }

        } else if(strcmp(texto_str, "FIM") == 0){
            /*Encerrar o programa, limpa a memoria alocada dinamicamente para a arvore e os medicamentos*/
            EsvaziarArvore(arv_medicamentos);

        } else{
            fprintf(arq_saida, "COMANDO NAO RECONHECIDO\n");
        }
    }

    /*Fecha os arquivos*/
    fclose(arq);
    fclose(arq_saida);
    return 0;
}
