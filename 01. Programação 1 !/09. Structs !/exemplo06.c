#include <stdio.h>

struct ponto {

	int x;
	int y;

};
//passagem por referencia

void insere(struct ponto *p){

	scanf("%d %d", &p -> x, &p -> y);

}


//passagem por valor
void imprime(struct ponto p){

	printf("pi = { %d , %d }\n", p.x, p.y);

}

// retornando uma estrutura
struct ponto inseree(void){

	struct ponto p;
	scanf("%d %d", &p.x, &p.y);
	
	return p;
}

int main(){
	struct ponto pi;
    insere(&pi);
	imprime(pi);
	
    struct ponto p;

    p = inseree();
    printf("p = { %d , %d }\n", p.x, p.y);

return 0;
}