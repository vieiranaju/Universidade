#include <stdio.h>

struct ponto {

	int x;
	int y;

};

struct novoPonto {

	int x;
	int y;

};

int main(){

	struct ponto p1 = {1, 2};
	struct ponto p2;
	struct novoPonto p3 = {2, 3};
	p2 = p1; //ok

	printf("p2 = { %d , %d }\n", p2.x, p2.y);

	//p2 = p3; -> estruturas diferentes, não funciona


return 0;
}