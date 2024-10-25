#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50

bool Palindromo(char *String, int n, int m) {

    if (n >= m) {
        return true;
    }

    if (String[n] != String[m]) {
        return false;
    }


    return Palindromo(String, n + 1, m - 1);
}

int main() {
    char String[MAX];
    int i = 0;

    printf("Escreva uma palavra:\n");
    fgets(String, MAX, stdin);

    String[strcspn(String, "\n")] = '\0';

    int tam = strlen(String) - 1;

    if (Palindromo(String, i, tam) == true)
        printf("'%s' e um palindromo.\n", String);
    else
        printf("'%s' nao r um palindromo.\n", String);

    return 0;
}