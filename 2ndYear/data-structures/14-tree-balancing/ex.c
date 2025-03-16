#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No* esq;
    struct No* dir;
    int altura;
} No;

int countOutPut=0;
No* Arvore = NULL;

void printNodes(FILE* f, No* no){
    if(no!=NULL){
        if(no->esq==NULL){
            fprintf(f, "%d -> %d \n", no->chave, no->esq->chave);
        }
        if(no->dir==NULL){
            fprintf(f, "%d -> %d \n", no->chave, no->dir->chave);
        }

        printNodes(f, no->esq);
        printNodes(f, no->dir);
    }
}



