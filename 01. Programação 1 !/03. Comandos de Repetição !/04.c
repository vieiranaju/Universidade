#include <stdio.h>

int main(){

    int n, d;
    float s;

    n = 1; 

    for(d=1; d<=50; d++){
        s = s + ((float)n/d);
        printf("\n%i/%i = %f", n, d, s);
        n = n + 2;
    }

}