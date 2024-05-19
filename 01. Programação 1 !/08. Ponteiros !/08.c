#include <stdio.h>

int main(void) {
  char frase[100] = "não gosto de programar em C";
  char *ptr = frase;
  
  ptr += 4; 

  while(*ptr != '\0') {
    printf("%c", *ptr);
    ptr++;
  }
  
  printf("\n");
  
  return 0;
}