#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>

// Definção do tipo Medicamento para a struct medicamento
typedef struct medicamento Medicamento;

// Definção do tipo Lista para a struct lista
typedef struct lista Lista ;

// Definções das funções que serão utilizadas no código:

/*Aloca a memoria e cria um novo Medicamento*/
Medicamento* CriaMedicamento (char * nome ,int codigo , float valor ,int * data_de_validade );

/*Inicia a Lista*/
Lista * CriaLista ();

/*Insere o novo medicamento na lista*/
Lista * InsereListaMedicamento (FILE* fp, Lista* l, Medicamento* m );

/*Retira o medicamento(Escolhido pelo ID) da lista*/
Lista * RetiraListaMedicamento (FILE* fp, Lista* l, int id_medicamento );

/*Verifica se medicamento correspondente ao ID existe na lista*/
int VerificaListaMedicamento (FILE* fp, Lista* l, int id_medicamento );

/*Verifica se existem medicamentos fora da validade*/
void VerificaListaValidade ( FILE* fp, Lista * l, int * data );

/*Altera o valor do medicamento*/
int AlterarPrecoMedicamento( FILE* fp, Lista * l, int id_medicamento, float valor );

/*Imprime todos os medicamentos existentes na lista*/
void ImprimeListaMedicamentos ( FILE* fp, Lista * l );

/*Ordena os medicamentos com base no valor*/
Lista* OrdenaListaValor (Lista* l);

/*Ordena os medicamentos com base na data de validade*/
Lista* OrdenaListaVencimento (Lista* l) ;

/*Libera a memoria alocada dinâmicamente*/
void EsvaziarLista(Lista* l);

#endif
