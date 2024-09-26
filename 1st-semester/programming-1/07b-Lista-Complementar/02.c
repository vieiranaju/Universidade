#include <stdio.h>
#define MAX 50

int main() {
    char matriz[5][50];
    char busca[50];
    int i, h = 0, j, f = 0;



    for(int i = 0; i < 5; i++){
    printf("Digite a string %d: ",i+1);
    fgets(matriz[i],50,stdin);
    }

    for (i = 0; i < 5; i++) {
            printf("%s\n", matriz[i]);
                   }


    printf("Digite uma string para buscar: ");
    scanf("%s", busca);

    int cont = 0;

    while (busca[cont] != '\0') {
        cont++;
    }


       for (j = 0; j < 5; j++) {
        h = 0;
        for (i = 0; i < cont; i++) {
            if (matriz[j][i] != busca[i]) {
                h++;
                break;
            }
        }
        if (h == 0) {
            printf("A string '%s' foi encontrada na linha %d.\n", busca, j + 1);

        }
    }

    if(f == 5){
        printf("A string '%s' n�o est� na matriz.\n", busca);
    }

    return 0;
}
