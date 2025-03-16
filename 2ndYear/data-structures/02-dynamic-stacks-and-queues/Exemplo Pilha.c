#include <stdio.h>
#include <stdlib.h>


struct Elemento{
    int num;
    struct Elemento *prox;
};

typedef struct Elemento Elemento;

struct Pilha{
    Elemento *topo;
};
typedef struct Pilha Pilha;

Elemento *aux;

Pilha* cria_pilha(){

    /*Alocação do ponteiro pi para controlar a pilha*/
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));

    if(pi!=NULL){
        pi->topo = NULL;
    }

    return pi;

}

void insere_elemento(Pilha *pi){

    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));

    printf("Numero a ser inserido na pilha:\n");
    scanf("%d", &novo->num);

    novo->prox = pi->topo;
    pi->topo = novo;

    printf("Ok");

}

void consulta_pilha(Pilha *pi){

    if(pi->topo == NULL){
        printf("Pilha Vazia!");
    }else{
        aux = pi->topo;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        }while(aux !=NULL);
    }
}

void remove_elemento_pilha(Pilha *pi){

    if(pi->topo==NULL){
        printf("Pilha Vazia!");
    }else{
        aux = pi->topo;
        printf("\n%d removido!", pi->topo->num);
        pi->topo = pi->topo->prox;
        free(aux);
    }
}

void esvazia_pilha(Pilha *pi){  if(pi->topo==NULL){
        printf("Pilha Vazia!");
    }else{
        aux = pi->topo;

        do{
            pi->topo = pi->topo->prox;
            free(aux);
            aux = pi->topo;
        }while(aux != NULL);
        printf("\nPilha Esvaziada");
    }
}

int main(){
    Pilha *pi = cria_pilha();

    return 0;
}
