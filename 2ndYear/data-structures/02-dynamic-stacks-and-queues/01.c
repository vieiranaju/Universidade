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

Elemento *aux, *aux1;

Pilha* cria_pilha(){

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

void esvazia_pilha(Pilha *pi){  

    if(pi->topo==NULL){
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

void compara_pilha(Pilha *p1, Pilha *p2){

    if(p1->topo==NULL && p2->topo==NULL){
        printf("Pilhas iguais e vazias!!");
    }else{

        aux = p1->topo; aux1 = p2->topo;

        do{

            if(aux == NULL && aux != aux1){
                printf("Pilha 2 é maior!");
            }

            else if(aux1 == NULL && aux != aux1){
                printf("Pilha 1 é maior!");
            }

            aux = aux->prox;
            aux1 = aux1->prox;

        }while(aux != NULL && aux1 != NULL);

        printf("Sao Iguais");

    }
}

void informacoes_pilha(Pilha *pi){

    int maior = 0, menor = 999999999, i = 0;
    float media = 0;

    if(pi->topo==NULL){
        printf("Pilha Vazia!");
    }else{

        aux = pi->topo;

        do{
            i++;

            if(maior < aux->num)
                maior = aux->num;

            if(menor > aux->num)
                menor = aux->num;


            media += aux->num;
            
            aux = aux->prox;
        }while(aux != NULL);

    media /= i;

    printf("\nMedia %f", media);
    printf("\nmenor: %d", menor);
    printf("\nmaior: %d", maior);

    }
}

Pilha* transferir_elementos(Pilha *p1){

    Pilha* p2 = (Pilha*) malloc(sizeof(Pilha));

    if(p1->topo==NULL){
        printf("Pilha Vazia!");
    }else{

        aux = p1->topo;


    }

    return p2;

}

int elementos_impares(Pilha *pi){

     int i = 0;

    if(pi->topo==NULL){
        printf("Pilha Vazia!");
    }else{

        aux = pi->topo;

        do{

            if(aux->num %2 != 0)
            i++;
                
            aux = aux->prox;
        }while(aux != NULL);

    }

    return i;
}

int elementos_pares(Pilha *pi){

     int i = 0;

    if(pi->topo==NULL){
        printf("Pilha Vazia!");
    }else{

        aux = pi->topo;

        do{

            if(aux->num %2 == 0)
            i++;
                
            aux = aux->prox;
        }while(aux != NULL);

    }

    return i;

}

int main(){
    Pilha *p1 = cria_pilha();
    Pilha *p2 = transferir_elementos(p1);

    insere_elemento(p1);
    insere_elemento(p1);
    insere_elemento(p1);
    insere_elemento(p1);

    compara_pilha(p1, p2);

    informacoes_pilha(p1);
    

    return 0;
}
