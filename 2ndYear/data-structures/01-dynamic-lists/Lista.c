#include <stdio.h>
#include <stdlib.h>

struct lista{

    int garibaldo;
    struct lista *prox;

};

typedef struct lista Lista;


Lista* cria_lista(void){

    return NULL;
}

Lista* insere_elemento(Lista* lst){

    Lista* novo = (Lista* ) malloc (sizeof(Lista*));

    printf("\nInsira o Garibaldo: ");
    scanf("%d", &novo->garibaldo);

    novo->prox = lst;

    return novo;
}

void imprime(Lista* lst){

    Lista* aux = lst;

    while(aux != NULL){
        printf("[%d] ", aux->garibaldo);
        aux = aux->prox;
    }

}

int lista_vazia(Lista* lst){
    return lst==NULL;
}

Lista* lst_insere_ordenado(Lista* lst, int valor) {

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->garibaldo = valor;

    Lista* ant = NULL;
    Lista* p = lst;

    while (p != NULL && p->garibaldo < valor) {
        ant = p;
        p = p->prox;
    }

    if (ant == NULL) {
        novo->prox = lst;
        lst = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;
}

Lista* ordenar_lst(Lista* lst) {
    Lista* ordenada = cria_lista();
    Lista* p = lst;

    while (p != NULL) {
        ordenada = lst_insere_ordenado(ordenada, p->garibaldo);
        p = p->prox;
    }

    free(lst);

    return ordenada;
}

Lista* busca(Lista* lst, int val){
    Lista*p = lst;

    while(p!=NULL){
        if(p->garibaldo == val){
            return p;
        }
    }

    return NULL;
}

Lista* inverter(Lista*lst){

    Lista* invertida = cria_lista();
    Lista* p = lst;

    while(p!=NULL){

        Lista* novo = (Lista* ) malloc (sizeof(Lista*));
            if (novo == NULL) {
            printf("Erro");
            exit(3);
        }
        novo->garibaldo = p->garibaldo;
        novo->prox = invertida;
        invertida = novo;
        p = p->prox;
    }

    free(lst);
    return invertida;

}

                                                                                               

int main(void){

    Lista* filomena;

    filomena = cria_lista();
    filomena = insere_elemento(filomena);
    filomena = insere_elemento(filomena);
    filomena = insere_elemento(filomena);
    filomena = insere_elemento(filomena);

    imprime(filomena);

    filomena = ordenar_lst(filomena);

    imprime(filomena);

}