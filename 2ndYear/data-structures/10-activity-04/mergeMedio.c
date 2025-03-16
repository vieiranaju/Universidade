#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iteracao = 0;

// Funcao para misturar o vetor
void mistureVetor ( int arr [] , int n ) {
    for ( int i = 0; i < n; i ++) {
        if (( rand () / ( double ) RAND_MAX ) < 0.5) {
            int j = ( int ) ((n -1) *( rand () /( double ) RAND_MAX ));
            int temp = arr [ i ];
            arr [i ] = arr [j ];
            arr [j ] = temp ;
        }
    }
}

void merge(int vetor[], int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[fim-inicio+1];
    while(com1<=meio && com2<=fim){
        iteracao++;
        if(vetor[com1] <= vetor[com2]){
            vetAux[comAux] = vetor[com1];
            com1++;
        }else{
            vetAux[comAux] = vetor[com2];
            com2++; }
        comAux++; 
    }
    while(com1<=meio){ //Caso ainda haja elementos na primeira metade
        iteracao++;
        vetAux[comAux] = vetor[com1];
        comAux++;com1++; }
    while(com2<=fim){ //Caso ainda haja elementos na segunda metade
        iteracao++;
        vetAux[comAux] = vetor[com2];
        comAux++;com2++; }
    for(comAux=inicio;comAux<=fim;comAux++){ //Move os elementos de volta para o vetor original
        iteracao++;
        vetor[comAux] = vetAux[comAux-inicio];
    }
}

void mergeSort(int* vetor, int inicio, int fim){
    if (inicio < fim) {
    int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
        iteracao++;
    }
 }

int main () {
    int tamanhos [] = {5000, 10000, 15000, 20000, 25000 , 30000 ,
    35000, 40000, 45000, 50000};
    int num_tamanhos = sizeof ( tamanhos ) / sizeof ( tamanhos [0]);

    // Abrir arquivo para armazenar os resultados
    FILE* fp_selection = fopen("MergeSortIteracoesCasoMedio.txt" , "w");

    srand ( time (0) ) ; // Iniciar os numeros aleatorios
    // Loop pelos tamanhos de vetor
    for ( int i = 0; i < num_tamanhos ; i ++) {
        int tam = tamanhos [i ];

        int * arr = ( int *) malloc ( tam * sizeof ( int ));
        // Preencher o array com valores crescentes
        for ( int j = 0; j < tam ; j ++) {
            arr [j ] = j;
        }
        // Executar 30 repeticoes para obter o caso medio
        for ( int j = 0; j < 30; j ++) {
            iteracao = 0;
            mistureVetor ( arr , tam );
            // Selection Sort
            mergeSort ( arr , 0, tam-1) ;
            fprintf ( fp_selection , "%d, " , iteracao );
        }
            fprintf ( fp_selection , "\n");
            free ( arr ); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose ( fp_selection );
    return 0;
}