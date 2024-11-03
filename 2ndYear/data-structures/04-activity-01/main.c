#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Lista{
    int info;
    struct Lista* prox;
};

typedef struct Lista Lista;

Lista* cria_noLista(void){

    return NULL;

}

Lista* lst_insere_ordenado(Lista* lst, int valor) {

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->info = valor;

    Lista* ant = NULL;
    Lista* p = lst;

    while (p != NULL && p->info < valor) {
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

void free_lista(Lista* lst){
    Lista* p = lst;
    Lista* prox;

    while(p != NULL){
        prox = p->prox;
        free(p);
        p = prox;
    }
}


int main(void){

    int  i;
    clock_t start, end;
    double timedif;
    int MAX;
    FILE *arq;

    arq = fopen("arquivo.txt", "w+");
 
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        for(int j = 0; j < 30; j ++){ 

            Lista* lst = cria_noLista(); 

            start = clock();
            for(i=MAX; i>0; i--){
                lst = lst_insere_ordenado(lst, i);
            }
            end = clock();
            timedif = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(arq, "%lf, ", timedif);
            free_lista(lst);
        }

        fprintf(arq, "\n");
    }
    fclose(arq);

    return 0;

}

