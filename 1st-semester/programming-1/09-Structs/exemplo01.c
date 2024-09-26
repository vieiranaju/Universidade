#include <stdio.h>

struct cliente {

	int codigo;
	char nome[50];
	int diaNasc;


}c1, c2; 

int main() {


  

  printf("\nInsira o Codigo (ID) e o dia de Nascimento do cliente 1\n");  
  scanf("%d %d", &c1.codigo, &c1.diaNasc );

  setbuf(stdin, NULL);
  printf("Insira o Nome: \n");
  fgets(c1.nome, 50, stdin);

  printf("\nID: %d", c1.codigo);
  printf("\nDia: %d", c1.diaNasc);
  printf("\nNome: %s", c1.nome);


  return 0;
}