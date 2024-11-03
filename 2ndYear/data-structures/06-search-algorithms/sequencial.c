int buscaLinear(int *V, int N, int elem){
    int i;
    for(i = 0; i<N; i++){
        if(elem == V[i]){
            return i;
        }
    }

    return -1;
}