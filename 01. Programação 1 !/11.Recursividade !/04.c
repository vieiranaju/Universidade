#include <stdio.h>

int multiplicacao(int n, int m){

	if(m==1)
	    return n;
	else
	    return n + multiplicacao(n, m-1);

}

int main (){

int x, y;

printf("valor A:");
scanf("%d", &x);

printf("valor B:");
scanf("%d", &y);



printf("multiplicacao %d x %d = %d\n", x, y, multiplicacao(x, y));

return 0;
}
