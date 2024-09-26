#include <stdio.h>

struct Data {

	int diaNasc;
	int mesNasc;
	int anoNasc;

};

struct cliente {

	int codigo;
	char nome[50];
	struct Data data;
	int sexo;

};

int main(){

    struct cliente c[50];
    int n;
    
        printf("\nQuantos Clientes?");
        scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nInsira a dia de nascimento do cliente %d\n", i + 1);  
        scanf("%d", &c[i].data.diaNasc);
        printf("\nInsira  de no mes de nascimento do cliente %d\n", i + 1);  
        scanf("%d", &c[i].data.mesNasc);
        printf("\nInsira o ano de nascimento do cliente %d\n", i + 1);  
        scanf("%d", &c[i].data.anoNasc);
    }

    for (int i = 0; i < n; i++) {
        printf("Cliente %d nasceu em %d / %d / %d \n", i+1, c[i].data.diaNasc, c[i].data.mesNasc, c[i].data.anoNasc);
    }

    return 0; 

}