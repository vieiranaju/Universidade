#include <stdio.h>

struct lojas {

	char nome[50];
    char endereco[50];
	int telefone;
    float preco;

}; 

int main() {

        struct lojas loja[100];
        int n;
        float media = 0;
    
    printf("\nQuantas Lojas deseja cadastrar?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        setbuf(stdin, NULL);
        printf("\nInsira o Nome: \n");
        fgets(loja[i].nome, 50, stdin);
        setbuf(stdin, NULL);
        printf("\nInsira o Endereco: \n");
        fgets(loja[i].endereco, 50, stdin);
        printf("\nInsira o telefone e o preco do produto\n");  
        scanf("%d %f", &loja[i].telefone, &loja[i].preco );
        media = media + loja[i].preco;
        }

        media = media / n;

        printf("As lojas com preco abaixo da media sao: ");

    for (int i = 0; i < n; i++) {

        if(loja[i].preco < media){
            printf("\n___________________________________");
            printf("\nLoja %s", loja[i].nome);
            printf("\nEndereco %s", loja[i].endereco);
            printf("\nTelefone %d", loja[i].telefone);
            printf("\npreco %.1f", loja[i].preco);
            printf("\n___________________________________");
        }
         
    }

    return 0;
}