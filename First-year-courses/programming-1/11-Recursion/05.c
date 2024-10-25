#include <stdio.h>

int potencia(int n, int m){

	if(m==1)
	    return n;
	else
	    return n * potencia(n, m-1);

}

int main (){

int x, y;

printf("valor A:");
scanf("%d", &x);

printf("valor B:");
scanf("%d", &y);



printf("%d^%d = %d\n", x, y, potencia(x, y));

return 0;
}
