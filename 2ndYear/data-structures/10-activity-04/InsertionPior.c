#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Implementacao do Insertion Sort
void insertionSort ( int arr [] , int n , int * iteracoes ) {
    *iteracoes = 0;
    
    for( int i = 1; i < n ; i++) {

        int aux = arr[i];
        int j = i -1;
        while(j>=0 && aux < arr[j]){
            (*iteracoes) ++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = aux;
    }
}


int main () {
int tamanhos [] = {5000, 10000, 15000, 20000, 25000 , 30000 ,
35000, 40000, 45000, 50000};
int num_tamanhos = sizeof ( tamanhos ) / sizeof ( tamanhos [0]);

// Abrir arquivo para armazenar os resultados
FILE* fp_selection = fopen("InsertionSortIteracoesCasoPior.txt" , "w");

srand ( time (0) ) ; // Iniciar os numeros aleatorios
// Loop pelos tamanhos de vetor
for ( int i = 0; i < num_tamanhos ; i ++) {
int tam = tamanhos [i ];

    int * arr = ( int *) malloc ( tam * sizeof ( int ));
    // Preencher o array com valores decrescentes
     for (int j = 0; j < tam; j++) {
            arr[j] = tam - j;
        }
    // Executar  para obter o pior caso
        int iteracoes ;
        // insertion Sort
        insertionSort ( arr , tam , & iteracoes ) ;
        fprintf ( fp_selection , "%d, " , iteracoes );
        
        fprintf ( fp_selection , "\n");
        free ( arr ); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose ( fp_selection );
    return 0;
}
