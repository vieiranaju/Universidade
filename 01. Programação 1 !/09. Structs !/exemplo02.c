#include <stdio.h>

struct cliente {

	int codigo;
	char nome[50];
	int diaNasc;


}; 


int main() {

        struct cliente C[50];
        int n;
    
    printf("\nQuantos Clientes?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nInsira o Codigo (ID) e o dia de Nascimento do cliente %d\n", i + 1);  
        scanf("%d %d", &C[i].codigo, &C[i].diaNasc );

        setbuf(stdin, NULL);
        printf("Insira o Nome: \n");
        fgets(C[i].nome, 50, stdin);
        }

    for (int i = 0; i < n; i++) {
        printf("\nCliente %d", i + 1);
        printf("\nID: %d", C[i].codigo);
        printf("\nDia: %d", C[i].diaNasc);
        printf("\nNome: %s", C[i].nome); 
    }


    return 0;
}