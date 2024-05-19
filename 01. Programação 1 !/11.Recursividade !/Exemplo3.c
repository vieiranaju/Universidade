#include <stdio.h>

int somatorio (int n){

	if(n==1)
	    return 1;
	else
	    return n + somatorio(n-1);

}

int main (){

int x;

printf("valor:");
scanf("%d", &x);


printf("somatorio de 1 ate %d = %d\n", x, somatorio(x));

return 0;
}
