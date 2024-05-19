#include <stdio.h>
#include <ctype.h>

float med(float x, float y, char z){
    float num;
    switch (z)
    {
    case 'a':
        return (x+y)/2;
    
    case 'p':
        return (x*2 + y*2)/4;

    case 'h': 
        
        num = 1/x + 1/y;
        return ((x + y)/num);

    }
    

        }
int main() {
        float a, b;
        char c, d;
      

    printf("Insira duas notas e o tipo de media a ser calculado, considerando:\n");
    printf("______________________________________\n");
    printf(" A - Média Aritmetica\n");
    printf(" P - Média Ponderada\n");
    printf(" H - Média Harmonica\n");
    printf("______________________________________\n");

    scanf("%f%f%c", &a, &b, &c);
        d = tolower(c);

    printf("A média é %f", med(a,b,d));


    
  return 0;
}