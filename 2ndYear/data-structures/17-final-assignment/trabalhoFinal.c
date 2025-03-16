#include "trabalhoFinal.h"

struct elemento {
    int num;
};

struct conjunto {
    Elemento* elemento;
    Set* prox;
};

Set* criaSet() {
    return NULL;
}

Elemento* criaElemento(int num) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL) return NULL;
    novo->num = num;
    return novo;
}

void add(Set** conjunto, int num) {
    Set* novo = (Set*)malloc(sizeof(Set));
    if (novo == NULL) return;
    novo->elemento = criaElemento(num);
    if (*conjunto == NULL || (*conjunto)->elemento->num >= num) {
        if (*conjunto != NULL && (*conjunto)->elemento->num == num) {
            free(novo->elemento);
            free(novo);
            return;
        }
        novo->prox = *conjunto;
        *conjunto = novo;
        return;
    }
    Set* atual = *conjunto;
    while (atual->prox != NULL && atual->prox->elemento->num < num) {
        atual = atual->prox;
    }
    if (atual->prox != NULL && atual->prox->elemento->num == num) {
        free(novo->elemento);
        free(novo);
        return;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

bool isEmpty(Set* conjunto) {
    return (conjunto == NULL);
}

int len(Set* conjunto) {
    int tamanho = 0;
    while (conjunto != NULL) {
        tamanho++;
        conjunto = conjunto->prox;
    }
    return tamanho;
}

bool isIn(Set* conjunto, Elemento* elemento) {
    while (conjunto != NULL) {
        if (conjunto->elemento->num == elemento->num) {
            return true;
        }
        conjunto = conjunto->prox;
    }
    return false;
}

bool isNotIn(Set* conjunto, Elemento* elemento) {
    return !isIn(conjunto, elemento);
}

bool isDisjoint(Set* conjunto1, Set* conjunto2) {
    Set* atual = conjunto1;
    while (atual != NULL) {
        if (isIn(conjunto2, atual->elemento)) {
            return false;
        }
        atual = atual->prox;
    }
    return true;
}

void removeElemento(Set** conjunto, Elemento* elemento) {
    Set* ant = NULL;
    Set* atual = *conjunto;
    while (atual != NULL && atual->elemento->num != elemento->num) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;
    if (ant == NULL) {
        *conjunto = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual->elemento);
    free(atual);
}

Elemento* pop(Set** conjunto) {
    if (*conjunto == NULL) return NULL;

    int count = len(*conjunto);
    srand(time(NULL));
    int index = rand() % count;

    Set* ant = NULL;
    Set* atual = *conjunto;
    for (int i = 0; i < index; i++) {
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL) {
        *conjunto = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    Elemento* resultado = atual->elemento;
    free(atual);

    return resultado;
}

void clear(Set* conjunto) {
    Set* atual = conjunto;
    while (atual != NULL) {
        Set* prox = atual->prox;
        free(atual->elemento);
        free(atual);
        atual = prox;
    }
}

Set* unionSet(Set* conjunto1, Set* conjunto2) {
    Set* resultado = criaSet();
    while (conjunto1 != NULL) {
        add(&resultado, conjunto1->elemento->num);
        conjunto1 = conjunto1->prox;
    }
    while (conjunto2 != NULL) {
        if (!isIn(resultado, conjunto2->elemento)) {
            add(&resultado, conjunto2->elemento->num);
        }
        conjunto2 = conjunto2->prox;
    }
    return resultado;
}

Set* intersection(Set* conjunto1, Set* conjunto2) {
    Set* resultado = criaSet();
    while (conjunto1 != NULL) {
        if (isIn(conjunto2, conjunto1->elemento)) {
            add(&resultado, conjunto1->elemento->num);
        }
        conjunto1 = conjunto1->prox;
    }
    return resultado;
}

Set* difference(Set* conjunto1, Set* conjunto2) {
    Set* resultado = criaSet();
    while (conjunto1 != NULL) {
        if (!isIn(conjunto2, conjunto1->elemento)) {
            add(&resultado, conjunto1->elemento->num);
        }
        conjunto1 = conjunto1->prox;
    }
    return resultado;
}

Set* symmetric_difference(Set* conjunto1, Set* conjunto2) {
    Set* resultado = criaSet();
    Set* temp1 = conjunto1; 
    Set* temp2 = conjunto2; 

    while (temp1 != NULL) {
        if (!isIn(conjunto2, temp1->elemento)) {
            add(&resultado, temp1->elemento->num);
        }
        temp1 = temp1->prox;
    }

    while (temp2 != NULL) {
        if (!isIn(conjunto1, temp2->elemento)) {  
            add(&resultado, temp2->elemento->num);
        }
        temp2 = temp2->prox;
    }

    return resultado;
}


bool isSubSet(Set* conjunto1, Set* conjunto2) {
    while (conjunto1 != NULL) {
        if (!isIn(conjunto2, conjunto1->elemento)) {
            return false;
        }
        conjunto1 = conjunto1->prox;
    }
    return true;
}

bool isSuperSet(Set* conjunto1, Set* conjunto2) {
    return isSubSet(conjunto2, conjunto1);
}

void copy(Set* conjunto1, Set** conjunto2) {
    while (conjunto1 != NULL) {
        add(conjunto2, conjunto1->elemento->num);
        conjunto1 = conjunto1->prox;
    }
}

void print(Set* conjunto) {
    while (conjunto != NULL) {
        printf("%d ", conjunto->elemento->num);
        conjunto = conjunto->prox;
    }
    printf("\n");
}
