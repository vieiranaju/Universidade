#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{

    int info;
    Lista *prox;

};

Lista* lst_cria(void){
    return NULL;
}

Lista* lst_insere (Lista* lst, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = lst;
    return novo;
}

void lst_imprime (Lista* lst){
    Lista* p;
    for (p = lst; p!= NULL; p = p->prox)
        printf("Info: %d\n", p->info);
}

int lst_vazia (Lista* lst){
    return (lst == NULL);
}

Lista* busca (Lista*lst, int v){
    Lista* p;

    for (p= lst; p!=NULL; p = p->prox){
        if(p->info == v)
            return p;
    }
    return NULL;

}

Lista* lst_retira (Lista* lst, int val){
    Lista* ant = NULL;
    Lista* p = lst;

    while(p!=NULL && p->info !=val){
        ant = p;
        p = p->prox;
    }

    if(p == NULL)
        return lst;

    if(ant==NULL){
        lst = p->prox;
    }
    else{
            ant->prox = p->prox;
    }

    free(p);
    return lst;

}

void lst_libera (Lista* lst){
    Lista* t;
    Lista* p = lst;

    while(p!=NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}

Lista* lst_insere_ordenado( Lista* lst, int val){
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = lst;

    while(p!=NULL && p->info<val){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;

    if(ant == NULL){
        novo->prox = lst;
        lst = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;
}

int lst_igual(Lista* lst1, Lista* lst2){
    Lista* p1;
    Lista* p2;

    for(p1=lst1, p2=lst2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if (p1->info != p2->info)
            return 0;
    }

    return p1==p2;
}

void insere_final_lst(Lista* lst, int val){

    Lista* p = lst;
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    Lista* ant = NULL;

    for (p = lst; p!= NULL; p = p->prox){
            ant = p;

    }

    novo->prox = NULL;
    ant->prox = novo;

}

Lista* inverte_lst(Lista* lst){

    Lista* p = lst;
    Lista* x = NULL;
    Lista* y = NULL;

    for (p = lst; p!= NULL; p = p->prox){
        
        y = p->prox;
        p->prox = x;
        x = p;
        p = y;


    }
    return x;
}

int elementos_lst(Lista* lst){

    int count = 0;
    Lista* p = lst;

    for (p = lst; p!= NULL; p = p->prox){
        count++;
    }

    return count;

}

Lista* lst_insere_ordenado_crescente( Lista* lst, int val){
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = lst;

    while(p!=NULL && p->info>val){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;

    if(ant == NULL){
        novo->prox = lst;
        lst = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst;
}


int main (void){

    Lista* lst;
    
    lst = lst_cria();
    lst = lst_insere(lst, 23);
    lst = lst_insere(lst, 45);

    insere_final_lst(lst, 21);

    lst_imprime(lst);

    printf("-----------------------\n");

    lst = inverte_lst(lst);
    lst_imprime(lst);

    lst_libera(lst);

    return 0;

}
