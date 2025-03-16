int buscaOrdenada(int *V, int N, int elem){
    int i;
    for(i = 0; i<N; i++){
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