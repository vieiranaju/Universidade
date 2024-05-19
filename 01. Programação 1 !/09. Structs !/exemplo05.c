#include <stdio.h>

struct ponto {

	int x;
	int y;

};

int main(){

	struct ponto p;
    struct ponto *pp = &p; //aponta para o endereço de p

    (*pp).x = 3;
    (*pp).y = 4;

return 0;
}