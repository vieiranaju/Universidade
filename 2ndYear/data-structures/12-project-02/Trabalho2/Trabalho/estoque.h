#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

// Tipo que define o medicamento
typedef struct medicamento Medicamento;
// Tipo que define a rvore
typedef struct arvore Arvore;
/* Cria um novo medicamento */
Medicamento* CriaMedicamento ( char* nome, int codigo, float valor, int* data_de_validade );
/* Cria uma arvore vazia */
Arvore* CriaArvore();
/* Insere um medicamento pelo codigo na arvore */
Arvore* InsereArvoreMedicamento (FILE* arq_saida, Arvore* a , Medicamento* m );
/* Retira um medicamento de uma determinada arvore */
Arvore* RetiraArvoreMedicamento (FILE* arq_saida, Arvore* a , int id_medicamento ) ;
/* Verifica se um medicamento esta presente em uma determinada arvore */
int VerificaArvoreMedicamento (FILE* arq_saida, Arvore* a , int id_medicamento ) ;
/* Verifica se existe um medicamento vencido em uma determinada arvore */
int VerificaArvoreValidade (FILE* arq_saida, Arvore* a , int * data ) ;
/* Busca o medicamento pelo ID e troca o valor quando encontrado*/
int AtualizaPrecoMedicamento(FILE* arq_saida, Arvore* a , int id_medicamento, float valor ) ;
/* Imprime em ordem pelo codigo todos os medicamentos de uma arvore*/
void ImprimeArvoreMedicamentos (FILE* arq_saida, Arvore* a ) ;

Arvore* EsvaziarArvore( Arvore* a ) ;

#endif // ESTOQUE_H_INCLUDED
