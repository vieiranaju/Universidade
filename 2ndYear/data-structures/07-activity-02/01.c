#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int geraPosRandomBusca(int tam){
	return ( int ) (( tam -1) *(( double ) rand () / RAND_MAX ));
}

int buscaBinaria(int MAX, int V[MAX], int elem){
    int inicio, meio, final;
    inicio = 0;
    final = MAX-1;

    while(inicio<=final){
        count++;
        meio = (inicio + final)/2;
        if(elem<V[meio]){
            final = meio - 1;
            
        }else{
            if(elem > V[meio]){
                inicio = meio+1;
                
            }else{
                return meio;
                
            }
        }
    }

    return -1;
}

int buscaOrdenada(int MAX, int V[MAX], int N, int elem){
    int i;
    for(i = 0; i<N; i++){
        count++;
        if(elem == V[i]){
            return i;
        }else{
            if(elem<V[i]){
                return -1;
            }
        } 
    }

    return -1;
}

int buscaLinear(int MAX, int V[MAX], int N, int elem){
    int i;
    for(i = 0; i<N; i++){
        count++;
        if(elem == V[i]){
            return i;
        }
    }

    return -1;
}

int main(void){

    int  i;
    int MAX;
    FILE *arq;

	//seed for random generator
	srand(time(0));

    arq = fopen("iteracoesCasoMedioBinaria.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        for(int j = 0; j < 30; j ++){ 
            int pos = geraPosRandomBusca(MAX);
            int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
            buscaBinaria(MAX, V, pos);
            fprintf(arq, "%d, ", count);
            count = 0;
        }

        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen("iteracoesPiorCasoBinaria.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
        buscaBinaria(MAX, V, MAX+1);
        fprintf(arq, "%d, ", count);
        count = 0;
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen("iteracoesCasoMedioOrdenada.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        for(int j = 0; j < 30; j ++){ 
            int pos = geraPosRandomBusca(MAX); 
            int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
            buscaOrdenada(MAX, V, MAX, pos);
            fprintf(arq, "%d, ", count);
            count = 0;
        }
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen("iteracoesPiorCasoOrdenada.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
        buscaOrdenada(MAX, V, MAX, MAX+1);
        fprintf(arq, "%d, ", count);
        count = 0;
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen("iteracoesCasoMedioLinear.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        for(int j = 0; j < 30; j ++){ 
            int pos = geraPosRandomBusca(MAX);
            int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
            buscaLinear(MAX, V, MAX, pos);
            fprintf(arq, "%d, ", count);
            count = 0;
        }
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen("iteracoesPiorCasoLinear.txt", "w+");
    for(MAX = 5000; MAX <= 50000; MAX += 5000){  
        int V[MAX]; 
            for(i=MAX; i>0; i--){
                V[i-1] = i-1;
            }
        buscaLinear(MAX, V, MAX, MAX+1);
        fprintf(arq, "%d, ", count);
        count = 0;
        fprintf(arq, "\n");
    }
    fclose(arq);

    

    return 0;

}

