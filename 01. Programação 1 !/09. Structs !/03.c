#include <stdio.h>

struct usuarios {

	char nome[50];
    int idade;
	char sexo;
    char estadoCivil;
    int amigos;
    int fotos;


}; 


int main() {
        
        int n;
    
    printf("\nQuantos Usuarios deseja cadastrar? ");
    scanf("%d", &n);

    struct usuarios C[n];

    for (int i = 0; i < n; i++) {

        printf("\n_________________cliente %d_________________", i + 1);
        setbuf(stdin, NULL);
        printf("\nInsira o Nome:\n");
        fgets(C[i].nome, 50, stdin);

        printf("\n-> Insira a idade:\n");  
        scanf("%d", &C[i].idade);

        setbuf(stdin, NULL);
        printf("\n-> Insira o Genero:\n");  
        printf("(m - masculino, f - feminino)\n");
        scanf("%c", &C[i].sexo);

        setbuf(stdin, NULL);
        printf("\n-> Insira o Estado Civil:\n");  
        printf("(s - solteiro, c - casado, n - namorando, d - divorciado)\n");
        scanf("%c", &C[i].estadoCivil);

        printf("\n-> Insira a quantidade de amigos:\n");  
        scanf("%d", &C[i].amigos);

        printf("\n-> Insira a quantidade de fotos no perfil:\n");  
        scanf("%d", &C[i].fotos);
        }

    for (int i = 0; i < n; i++) {
        printf("\n-------------------------------------");
        printf("\nCliente %d\n", i + 1);
        printf("\nNome: %s", C[i].nome);
        printf("Idade: %d", C[i].idade);
        printf("\nGenero: %c", C[i].sexo); 
        printf("\nEstado Civil: %c", C[i].estadoCivil);
        printf("\nQuantidade de amigos: %d", C[i].amigos);
        printf("\nQuantidade de fotos no perfil: %d", C[i].fotos);    
    }


    return 0;
}