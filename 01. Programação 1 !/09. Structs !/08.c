// Fa ̧ca um programa para gerenciar a ficha de registro de passageiros de ˆonibus de uma
// empresa. Os ˆonibus possuem 44 lugares numerados de 1 a 44. O programa deve ler
// uma lista de registro de passageiros, com o n ́umero da passagem, data, de (origem), para
// (destino), hor ́ario, poltrona, idade e nome do passageiro. A entrada termina quando o valor
// do n ́umero da passagem for −1.
// Ao final, o programa deve exibir o nome de todos os passageiros que estiverem acima da
// m ́edia das idades e que estiverem sentados nas poltronas pares.
#include <stdio.h>
#define MAX 100

struct Data {

	int dia, mes, hora, minuto;

};

struct registro {

    int numPassagem, poltrona, idade;
    struct Data data;
	char de[MAX], para[MAX], nome[MAX];

}; 


int main() {

        struct registro C[MAX];
        int i = 0, cont = 0;
        float mediaIdade = 0;

    do{
        printf("\n_________________Passageiro %d_________________", i + 1);


        printf("\n-> Insira o numero da passagem:\n");  
        scanf("%d", &C[i].numPassagem);

        if (C[i].numPassagem != -1){

            printf("\n-> Insira a data da viagem:\n");  
            scanf("%d %d", &C[i].data.dia, &C[i].data.mes);

            printf("\n-> Insira o horario (hora e minutos) da viagem:\n");  
            scanf("%d %d", &C[i].data.hora, &C[i].data.minuto);

            setbuf(stdin, NULL);
            printf("\n-> Insira o Local de Partida: \n");
            fgets(C[i].de, MAX, stdin);

            setbuf(stdin, NULL);
            printf("\n-> Insira o Local de Destino: \n");
            fgets(C[i].para, MAX, stdin);

            printf("\n-> Insira o poltrona (1 - 44):\n");  
            scanf("%d", &C[i].poltrona);

            printf("\n-> Insira a idade:\n");  
            scanf("%d", &C[i].idade);

            setbuf(stdin, NULL);
            printf("\n-> Insira o Nome: \n");
            fgets(C[i].nome, MAX, stdin);

            i++;

            mediaIdade += (float)C[i].idade;
        }

        

        } while (C[i].numPassagem != -1);

        mediaIdade = mediaIdade/i;

        printf("\nPassageiros acima da media de idade e sentados em poltronas pares:\n");


    for (int j = 0; j < i; j++) {

        if(C[j].idade > mediaIdade && C[j].poltrona %2 == 0){
            printf("\nNome: %s", C[j].nome);
            cont++;
            }
        
    }
    if(cont == 0){
        printf("\nNenhum passageiro atende aos criterios!");
    }

    return 0;
}