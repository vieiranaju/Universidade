#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct pilha{
    int elementos[MAX];
    int topo;
};
typedef struct pilha Pilha;

void empilha(Pilha *p, int A){
    p->elementos[p->topo] = A;
    p->topo = p->topo + 1;
}

int desempilha(Pilha *p){
    p->topo = p->topo -1;
    return p->elementos[p->topo];
}
