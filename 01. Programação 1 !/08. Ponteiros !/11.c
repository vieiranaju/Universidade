#include <stdio.h>
#define MAX 100

int totalPalavras(char *string) {

  int count = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == ' ') {
      count++;
    }
  }
  return count + 1;
}

int main() {

  char string[MAX];

  printf("Entre com a string: ");
  fgets(string, MAX, stdin);

  printf("\nExistem %d palavras !", totalPalavras(string));

  return 0;
}