#include "trabalhoFinal.h"

int main() {
    Set* conjunto1 = criaSet();
    Set* conjunto2 = criaSet();

    add(&conjunto1, 10);
    add(&conjunto1, 20);
    add(&conjunto1, 30);
    add(&conjunto1, 42);
    add(&conjunto1, 57);
    add(&conjunto2, 30);
    add(&conjunto2, 42);
    add(&conjunto2, 57);

    printf("Conjunto 1: ");
    print(conjunto1);
    printf("Conjunto 2: ");
    print(conjunto2);

    printf("Tamanho do Conjunto 1: %d\n", len(conjunto1));
    printf("Tamanho do Conjunto 2: %d\n", len(conjunto2));

    Elemento* e1 = criaElemento(20);
    printf("Elemento 20 esta no Conjunto 1: %s\n", isIn(conjunto1, e1) ? "Sim" : "Nao");

    printf("Conjuntos sao disjuntos: %s\n", isDisjoint(conjunto1, conjunto2) ? "Sim" : "Nao");

    Set* uniao = unionSet(conjunto1, conjunto2);
    printf("Uniao dos conjuntos: ");
    print(uniao);

    Set* intersecao = intersection(conjunto1, conjunto2);
    printf("Intersecao dos conjuntos: ");
    print(intersecao);

    Set* diferenca = difference(conjunto1, conjunto2);
    printf("Diferenca do Conjunto 1 para o Conjunto 2: ");
    print(diferenca);

    Set* dif_simetrica = symmetric_difference(conjunto1, conjunto2);
    printf("Diferenca Simetrica dos conjuntos: ");
    print(dif_simetrica);

    printf("Conjunto 1 e subconjunto do Conjunto 2: %s\n", isSubSet(conjunto1, conjunto2) ? "Sim" : "Nao");
    printf("Conjunto 1 e superconjunto do Conjunto 2: %s\n", isSuperSet(conjunto1, conjunto2) ? "Sim" : "Nao");

    removeElemento(&conjunto1, e1);
    printf("Conjunto 1 apos remover elemento 20: ");
    print(conjunto1);

    Elemento* popped = pop(&conjunto1);
    printf("Conjunto 1 apos remocao aleatoria: ");
    print(conjunto1);

    Set* copia = criaSet();
    copy(conjunto2, &copia);
    printf("Copia do Conjunto 2: ");
    print(copia);

    clear(conjunto2);
    clear(uniao);
    clear(intersecao);
    clear(diferenca);
    clear(dif_simetrica);
    clear(copia);

    return 0;
}
