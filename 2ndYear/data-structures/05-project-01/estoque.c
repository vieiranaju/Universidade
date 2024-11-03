#include "estoque.h"
#include <stdlib.h>
#include <string.h>

/*Estrutura medicamento, que armazena as informações de cada um
Tipo definido em estoque.h, então é acessada apenas por 'Medicamento'*/
struct medicamento {
    char nome [30];
    int codigo ;
    float valor ;
    int data [3];
};

/*Estrutura lista, que armazena o medicamento
Tipo definido em estoque.h, então é acessada apenas por 'Lista'*/
struct lista {
    Medicamento* m ;
    Lista* prox ;
};

/*Inicializa a Lista*/
Lista* CriaLista (){

    return NULL;

}

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

Lista * InsereListaMedicamento (FILE* fp , Lista* l , Medicamento *m ){

    /*Aloca a memoria para o novo elemento da lista*/
    Lista *lst = (Lista*) malloc(sizeof(Lista));

    if (lst == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    /*Salva o novo medicamento e o primeiro elemento da lista recebida, que passa a ser o segundo*/
    lst->m = m;
    lst->prox = l;

    /*Mensagem de confirmação*/
    fprintf(fp,"MEDICAMENTO %s %d ADICIONADO\n",m->nome,m->codigo);

    /*Retorna o novo inicio da lista*/
    return lst;

}

/*Retira o Medicamento da Lista*/
Lista * RetiraListaMedicamento (FILE* fp , Lista* l , int id_medicamento ){
    /*Variaveis Auxiliares para percorrer a lista*/
    Lista* ant = NULL;
    Lista* p = l;

    /*Percorre a lista até encontrar o medicamento de ID correspondente*/
    while(p!=NULL && p->m->codigo != id_medicamento){
        ant = p;
        p = p->prox;
    }

    /*Percorreu toda a lista e não encontrou o medicamento*/
    if(p == NULL){
        fprintf(fp,"MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
        return l;
    }/*É o primeiro elemento da lista, então o inicio passa a ser o proximo elemento*/
    if(ant==NULL){
        free(p->m);
        l = p->prox;
    }/*Elemento no meio da lista, o proximo do elemento anterior passa a ser o proximo ao elemento correspondente*/
    else{
        ant->prox = p->prox;
    }

    /*Mensagem de confirmação*/
    fprintf(fp,"MEDICAMENTO %s %d RETIRADO\n",p->m->nome,id_medicamento);

    /*Liberar memoria alocada na lista e no medicamento, então retorna a lista atualizada*/
    free(p->m);
    free(p);
    return l;
}

void ImprimeListaMedicamentos (FILE* fp , Lista* l){

    /*Variavel auxiliar para percorrer a lista*/
    Lista* p = l;

    if(p == NULL){
        fprintf(fp,"LISTA VAZIA\n");
    }

    /*Percorre até o final imprimindo os medicamentos presentes na lista*/
    while(p!=NULL){
        fprintf(fp,"%s %d %.1f %d %d %d \n",p->m->nome,p->m->codigo,p->m->valor, p->m->data[0],p->m->data[1],p->m->data[2]);
        p = p->prox;
    }
}

int VerificaListaMedicamento (FILE * fp , Lista* l , int id_medicamento){

    /*Variavel auxiliar para percorrer a lista*/
    Lista* p = l;

    /*Percorre a lista até encontrar o medicamento de ID correspondente*/
    while(p!=NULL && p->m->codigo != id_medicamento){
        /*Imprime as informações do medicamento caso encontre e encerra a busca*/
        if(p->m->codigo == id_medicamento){
            fprintf(fp,"%s %d %.1f %d %d %d \n",p->m->nome,p->m->codigo,p->m->valor, p->m->data[0],p->m->data[1],p->m->data[2]);
            return 1;
        }
        p = p->prox;
    }

    /*Percorreu toda a lista e não encontrou o medicamento*/
    fprintf(fp,"MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    return 0;
}

int AlterarPrecoMedicamento( FILE* fp , Lista *l , int id_medicamento, float valor){

    /*Variavel auxiliar para percorrer a lista*/
    Lista* p = l;

    /*Percorre a lista até encontrar o medicamento de ID correspondente*/
    while(p!=NULL && p->m->codigo != id_medicamento){
        p = p->prox;
    }
    /*Caso o elemento seja encontrado altera o valor, imprime a mensagem de confirmação e encerra a função*/
    if(p->m->codigo == id_medicamento){
        p->m->valor = valor;
        fprintf(fp,"PRECO ATUALIZADO %s %d %.1f\n", p->m->nome, p->m->codigo, p->m->valor);
        return 0;
    }else{
        /*Medicamento não encontrado*/
        fprintf(fp,"MEDICAMENTO NAO ENCONTRADO NA LISTA\n");
    }
    return 0;
}

void VerificaListaValidade(FILE* fp , Lista* l , int* data){

    /*Variaveis auxiliares*/
    Lista* p = l;
    int i = 0;

    if(p == NULL){
        fprintf(fp,"LISTA VAZIA\n");
    }

    while(p!=NULL){

        /*Verifica o ano, caso não seja maior, mas igual, verifica o mês, segue a mesma lógica para o dia
        i utilizado para verificar se pelo menos um elemento vencido foi encontrado*/
        if (p->m->data[2] < data[2]) {
            fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", p->m->nome, p->m->codigo);
            i++;
        } else if (p->m->data[2] == data[2]) {
            if (p->m->data[1] < data[1]) {
                fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", p->m->nome, p->m->codigo);
                i++;
            } else if (p->m->data[1] == data[1]) {
                if (p->m->data[0] < data[0]) {
                    fprintf(fp, "MEDICAMENTO %s %d VENCIDO\n", p->m->nome, p->m->codigo);
                    i++;
                }
            }
        }

        p = p->prox;
    }
    if(i == 0){
        fprintf(fp,"MEDICAMENTO VENCIDO NAO ENCONTRADO NA LISTA\n");
    }

}

/*Função Auxiliar para inverter medicamentos na lista utilizando um temporario*/
void InverteMedicamentos(Lista* a, Lista* b) {
    Medicamento* temp = a->m;
    a->m = b->m;
    b->m = temp;
}

Lista* OrdenaListaValor (Lista* l){
    Lista *p, *q;

    /*Verifica se cada elemento é menor que o anterior, caso seja inverte*/
    for (p = l; p != NULL; p = p->prox) {
        Lista *menor = p;

        for (q = p->prox; q != NULL; q = q->prox) {
            if (q->m->valor < menor->m->valor) {
                menor = q;
            }
        }

        if (menor != p) {
            InverteMedicamentos(p, menor);
        }
    }
    /*Retorna a lista ordenada*/
    return l;

}

Lista* OrdenaListaVencimento (Lista* l){

    /*Variaveis auxiliares*/
     Lista *p, *q;

    for (p = l; p != NULL; p = p->prox) {
        Lista *menor = p;
        /*Verificar se a data é menor que as anteriores e inverter caso sejam*/
        for (q = p->prox; q != NULL; q = q->prox) {
            if (q->m->data[2] < menor->m->data[2] ||
                (q->m->data[2] == menor->m->data[2] && q->m->data[1] < menor->m->data[1]) ||
                (q->m->data[2] == menor->m->data[2] && q->m->data[1] == menor->m->data[1] && q->m->data[0] < menor->m->data[0])) {
                menor = q;
            }
        }

        if (menor != p) {
            InverteMedicamentos(p, menor);
        }
    }

    /*Retorna a lista ordenada*/
    return l;

}

void EsvaziarLista(Lista* l) {

    Lista* p = l;
    /*Percorrer a lista liberando a memoria alocada em cada um dos elementos*/
    while (p != NULL) {
        l = l->prox;
        free(p->m);
        free(p);
        p = l;
    }
}


