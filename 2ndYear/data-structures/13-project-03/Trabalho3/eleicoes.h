#ifndef ELEICOES_H_INCLUDED
#define ELEICOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chapa Chapa;
typedef struct arvore Arvore;
typedef struct categoriaVotos categoriaVotos;

Arvore* CriaArvore();

Chapa* CriaChapa(char* nomeCandidato, int numero, int* dataNascimento, char* nomeVice);

Arvore* InsereArvoreChapa(Arvore* a, Chapa* c);

void ImprimeArvoreChapas(Arvore* arvoreChapas);

void Votacao(Arvore* arvChapas, int totalPopulacao, FILE* arquivoTurno);

categoriaVotos* Votar(Arvore* arvChapas, int numero, categoriaVotos* tipoVotos);

int VerificaSegundoTurno(Arvore* arvChapas, int totalPopulacao);

Arvore* AtualizaChapasSegundoTurno(Arvore* arvChapas, Chapa* primeiro, Chapa* segundo);

void EncontraDoisMaisVotados(Arvore* arvoreChapas, Chapa** primeiro, Chapa** segundo);

void ImprimeArvoreCandidatos(FILE* arquivoTurno, Arvore* arvoreChapas, int totalEleitores, Chapa** candidatoVencedor);

void ImprimeBoletim(Arvore* arvoreChapas, FILE* arquivoTurno, categoriaVotos* tipoVotos, int totalEleitores);

int ComparaDataNascimento(int data1[3], int data2[3]);

int ContarTotalChapas(Arvore* arvoreChapas);

Arvore* EsvaziarArvore(Arvore* arvChapas);

#endif // ELEICOES_H_INCLUDED
