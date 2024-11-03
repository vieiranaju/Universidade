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

void troca(int vet[], int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
    iteracao++;

}


int particiona(int vet[], int inicio, int fim){

    int pivo, pivo_indice, i;
    pivo = vet[fim]; // o pivô é sempre o último elemento
    pivo_indice = inicio;
    for(i = inicio; i < fim; i++){
        // verifica se o elemento é <= ao pivô
        if(vet[i] <= pivo){
            troca(vet, i, pivo_indice); // realiza a troca
            pivo_indice++; // incrementa o pivo_indice
        }
    }
    troca(vet, pivo_indice, fim); // troca o pivô
    return pivo_indice; // retorna o índice do pivô
}

int particiona_random(int vet[], int inicio, int fim){
int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
troca(vet, pivo_indice, fim);
return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        // função particionar retorna o índice do pivô
        int pivo_indice = particiona_random(vet, inicio, fim);
        // chamadas recursivas quick_sort
        quick_sort(vet, inicio, pivo_indice - 1);
        quick_sort(vet, pivo_indice + 1, fim);
    }
}

int main () {
    int tamanhos [] = {5000, 10000, 15000, 20000, 25000 , 30000 ,
    35000, 40000, 45000, 50000};
    int num_tamanhos = sizeof ( tamanhos ) / sizeof ( tamanhos [0]);

    // Abrir arquivo para armazenar os resultados
    FILE* fp_selection = fopen("QuickSortIteracoesRand.txt" , "w");

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
            quick_sort( arr , 0, tam-1) ;
            fprintf ( fp_selection , "%d, " , iteracao );
        }
            fprintf ( fp_selection , "\n");
            free ( arr ); // Liberar memoria do array
    }
    // Fechar arquivo
    fclose ( fp_selection );
    return 0;
}