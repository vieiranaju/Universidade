#ifndef TRABALHOFINAL_H_INCLUDED
#define TRABALHOFINAL_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct conjunto Set;
typedef struct elemento Elemento;

Set* criaSet();

Elemento* criaElemento(int num);

void add(Set** conjunto, int num);

bool isEmpty(Set* conjunto);

int len(Set* conjunto);

bool isIn(Set* conjunto, Elemento* elemento);

bool isNotIn(Set* conjunto, Elemento* elemento);

bool isDisjoint(Set* conjunto1, Set* conjunto2);

void removeElemento(Set** conjunto, Elemento* elemento); 

Elemento* pop(Set** conjunto);

void clear(Set* conjunto);

Set* unionSet(Set* conjunto1, Set* conjunto2);

Set* intersection(Set* conjunto1, Set* conjunto2);

Set* difference(Set* conjunto1, Set* conjunto2);

Set* symmetric_difference(Set* conjunto1, Set* conjunto2);

bool isSubSet(Set* conjunto1, Set* conjunto2);

bool isSuperSet(Set* conjunto1, Set* conjunto2);

void copy(Set* conjunto1, Set** conjunto2);

void print(Set* conjunto);

#endif
