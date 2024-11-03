#include "arv.h"
#include <stdlib.h>
#include <string.h>

struct noArv{
    char info;
    struct noArv* esq;
    struct noArv* dir;
};

NoArv* arv_criavazia (void)
{
    return NULL;
}

NoArv* arv_cria(char c, NoArv* sae, NoArv* sad)
{
    NoArv* p=(NoArv*)malloc(sizeof(NoArv));
    if(p==NULL) exit(1);
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

NoArv* arv_libera (NoArv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int arv_vazia (NoArv* a){
    return a==NULL;
}

int arv_pertence (NoArv* a, char c){
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info==c ||
    arv_pertence(a->esq,c) ||
    arv_pertence(a->dir,c);
}

void arv_imprime (NoArv* a)
{
    if (!arv_vazia(a)){
        printf("%c ",a->info); /* mostra raiz */
        arv_imprime(a->esq); /* mostra sae */
        arv_imprime(a->dir); /* mostra sad */
    }
}

NoArv* abb_insere (NoArv* a, int v){
    if (a==NULL) {
        a = (NoArv*)malloc(sizeof(NoArv));
        a->info = v;
        a->esq = a->dir = NULL;
    }else if (v < a->info)
        a->esq = abb_insere(a->esq,v);

    else /* v >= a->info */
        a->dir = abb_insere(a->dir,v);

    return a;

}

NoArv* abb_retira (NoArv* r, int v){
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abb_retira(r->dir, v);
    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
            free (r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL) {
            NoArv* t = r;
            r = r->dir;
            free (t);
            /* só tem filho à esquerda */
        }else if (r->dir == NULL){
            NoArv* t = r;
            r = r->esq;
            free (t);
        }
            /* nó tem os dois filhos */
        else {
            NoArv* f = r->esq;
            while (f->dir != NULL) {
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
    }
        return r;
    }
