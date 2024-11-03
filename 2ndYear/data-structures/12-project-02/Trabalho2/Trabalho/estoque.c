#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

struct medicamento {
    char nome [20];
    int codigo ;
    float valor ;
    int data [3];
};

struct arvore {
    Medicamento* m ;
    Arvore* esquerda ;
    Arvore* direita ;
};

Medicamento* CriaMedicamento (char* nome ,int codigo ,float valor ,int* data_de_validade ){

    /*Aloca a memoria para o novo medicamento*/
    Medicamento *novo = (Medicamento*) malloc(sizeof(Medicamento));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    /*Armazenando os valores lidos no arquivo no campo correspondente*/
    strcpy(novo->nome, nome);
    novo->codigo = codigo;
    novo->valor = valor;
    novo->data[0] = data_de_validade[0];
    novo->data[1] = data_de_validade[1];
    novo->data[2] = data_de_validade[2];

    /*Retorna o novo medicamento*/
    return novo;

}

Arvore* CriaArvore(){

    return NULL;

}

Arvore* InsereArvoreMedicamento (FILE* arq_saida, Arvore* a, Medicamento* novo){

    if(a == NULL){
        Arvore* p = (Arvore*)malloc(sizeof(Arvore));
        if(p==NULL) exit(1);

        p->m = novo;
        p->esquerda = NULL;
        p->direita = NULL;

        fprintf(arq_saida, "MEDICAMENTO %s %d ADICIONADO\n", p->m->nome, p->m->codigo);

        return p;
    }else if(a->m->codigo > novo->codigo){
        a->esquerda = InsereArvoreMedicamento(arq_saida, a->esquerda, novo);
    }else{
        a->direita = InsereArvoreMedicamento(arq_saida, a->direita, novo);
    }

    return a;
}

int ArvoreVazia(Arvore* arv)
{
    return arv==NULL;
}

Arvore* EsvaziarArvore(Arvore* a){
    if (!ArvoreVazia(a)){
        EsvaziarArvore(a->esquerda);
        EsvaziarArvore(a->direita);
        free(a->m);
        free(a);
    }
    return NULL;
}

int VerificaArvoreMedicamento (FILE* arq_saida, Arvore* a , int id_medicamento ){

    if (ArvoreVazia(a)){
        return 0; /* árvore vazia: não encontrou */

    }else{
        if(a->m->codigo==id_medicamento){
            fprintf(arq_saida,"%s %d %.1f %d %d %d \n",
                    a->m->nome,
                    a->m->codigo,
                    a->m->valor,
                     a->m->data[0],
                     a->m->data[1],
                     a->m->data[2]);
        }
        return a->m->codigo==id_medicamento ||
        VerificaArvoreMedicamento(arq_saida, a->esquerda,id_medicamento) ||
        VerificaArvoreMedicamento(arq_saida, a->direita,id_medicamento);
    }
}

int VerificaArvoreValidade(FILE* arq_saida, Arvore* a, int* data) {
    if (ArvoreVazia(a)) {
        return 0; // Árvore vazia: não encontrou medicamentos vencidos
    }

    int medicamentos_vencidos = 0;

    // Verifica se o medicamento atual está vencido
    if (a->m->data[2] < data[2] || // Ano vencido
        (a->m->data[2] == data[2] && a->m->data[1] < data[1]) || // Mês vencido
        (a->m->data[2] == data[2] && a->m->data[1] == data[1] && a->m->data[0] < data[0])) // Dia vencido
    {
        fprintf(arq_saida, "MEDICAMENTO %s %d VENCIDO\n", a->m->nome, a->m->codigo);
        medicamentos_vencidos++;
    }

    // Verifica as subárvores esquerda e direita
    medicamentos_vencidos += VerificaArvoreValidade(arq_saida, a->esquerda, data);
    medicamentos_vencidos += VerificaArvoreValidade(arq_saida, a->direita, data);

    return medicamentos_vencidos;
}


int AtualizaPrecoMedicamento(FILE* arq_saida, Arvore* a , int id_medicamento, float valor ){
    if (ArvoreVazia(a)){
        fprintf(arq_saida, "MEDICAMENTO NAO ENCONTRADO NA ARVORE\n");
        return 0; /* árvore vazia: não encontrou */

    }else{
        if(a->m->codigo==id_medicamento){
            a->m->valor = valor;
            fprintf(arq_saida,"PRECO ATUALIZADO %s %d %.1f\n",a->m->nome,a->m->codigo,a->m->valor);
        }
        return a->m->codigo==id_medicamento ||
        AtualizaPrecoMedicamento(arq_saida, a->direita, id_medicamento, valor) ||
        AtualizaPrecoMedicamento(arq_saida, a->esquerda, id_medicamento, valor);
    }
}

void ImprimeArvoreMedicamentos(FILE* arq_saida, Arvore* a ){

    if (!ArvoreVazia(a)){
        ImprimeArvoreMedicamentos(arq_saida, a->esquerda);
        fprintf(arq_saida,"%s %d %.1f %d %d %d\n",
                a->m->nome,
                a->m->codigo,
                a->m->valor,
                a->m->data[0],
                a->m->data[1],
                a->m->data[2]);
        ImprimeArvoreMedicamentos(arq_saida, a->direita);
    }
}

Arvore* RetiraArvoreMedicamento(FILE* arq_saida, Arvore* a, int id_medicamento) {
    if (a == NULL)
        return NULL; /* Árvore vazia: não encontrou */

    if (id_medicamento < a->m->codigo) {
        /* O id é menor que o do nó, busca na subárvore esquerda */
        a->esquerda = RetiraArvoreMedicamento(arq_saida, a->esquerda, id_medicamento);
    } else if (id_medicamento > a->m->codigo) {
        /* O id é maior que o do nó, busca na subárvore direita */
        a->direita = RetiraArvoreMedicamento(arq_saida, a->direita, id_medicamento);
    } else {
        /* Achou o nó a ser removido */
        if (a->esquerda == NULL && a->direita == NULL) {
            /* Nó sem filhos */
            fprintf(arq_saida, "MEDICAMENTO %s %d REMOVIDO\n", a->m->nome, a->m->codigo);
            free(a->m);
            free(a);
            a = NULL;
        } else if (a->esquerda == NULL) {
            /* Nó só tem filho à direita */
            Arvore* t = a;
            a = a->direita;
            fprintf(arq_saida, "MEDICAMENTO %s %d REMOVIDO\n", t->m->nome, t->m->codigo);
            free(t->m);
            free(t);
        } else if (a->direita == NULL) {
            /* Nó só tem filho à esquerda */
            Arvore* t = a;
            a = a->esquerda;
            fprintf(arq_saida, "MEDICAMENTO %s %d REMOVIDO\n", t->m->nome, t->m->codigo);
            free(t->m);
            free(t);
        } else {
            /* Nó tem os dois filhos */
            Arvore* f = a->esquerda;
            while (f->direita != NULL) {
                f = f->direita;
            }
            /* Substitui o valor atual pelo predecessor em ordem */
            Medicamento* temp = a->m;
            a->m = f->m;
            f->m = temp; /* Troca para manter o dado correto no nó a ser removido */

            /* Remove o predecessor da subárvore esquerda */
            a->esquerda = RetiraArvoreMedicamento(arq_saida, a->esquerda, f->m->codigo);
        }
    }
    return a;
}


