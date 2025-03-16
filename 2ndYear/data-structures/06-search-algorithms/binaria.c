int buscaBinaria(int *V, int N, int elem){
    int i, inicio, meio, final;
    inicio = 0;
    final = N-1;

    while(inicio<=final){
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