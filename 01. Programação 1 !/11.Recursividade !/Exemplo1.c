#include <stdio.h>

int fatorial (int n){

	if(n==0)
	    return 1;
	else
	    return n * fatorial(n-1);

}

int main (){

int x;

printf("valor:");
scanf("%d", &x);


printf("Fatorial de %d = %d\n", x, fatorial(x));

return 0;
}
