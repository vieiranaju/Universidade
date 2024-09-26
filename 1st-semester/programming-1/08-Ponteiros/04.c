#include <stdio.h>
#define MAX 255

int main (){
 char str[MAX] , caractere ;
 int count = 0 ;

 printf( "Entre com a string: " ) ;
 fgets(str, MAX, stdin) ;
 printf("Entre com o caractere : " ) ;
 scanf(" %c" , &caractere) ;

  char *p = str;

  for (int i = 0;  *(p + i) != '\0'; ++ i ) {
    if (  *(p + i) == caractere ){
      printf ("%d ", i) ;
      count++;
    }
 }
  if ( count == 0 )
    printf( " -1\n" );
   
return 0;
}
