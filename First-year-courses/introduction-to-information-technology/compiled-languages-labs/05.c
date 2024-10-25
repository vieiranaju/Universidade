#include <stdio.h>

int main() {
    int p = 69, s = 0; 
    // p é o número pré-selecionado e s o valor a ser escolhido pelo usuário

    while (p != s) {
        scanf("%d", &s);
        
        if (s == p) {
            printf("Acertou!\n");
            // se s for igual a p, então o usuário acertou e o programa é finalizado
            break;
        } else {
            if (p > s) {
                printf("O número é maior.\n");
                // verifica se s é maior que p e mostra caso seja
            } else {
                printf("O resultado é menor.\n");
                // verifica se s é menor que p e mostra caso seja
            }
        }
    }

    return 0;
}
