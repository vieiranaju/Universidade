#include <stdio.h>
#include <math.h>

 double area(int r){
 double a = pow(r,2) * 3.14;

 return a;
 }
 

 int main () {

    int x;

printf("Qual o raio da circunferencia? ");
 scanf("%i", &x);

 printf("%.2lf", area(x));

 return 0;
 }