#include <math.h>
#include <stdio.h>

double IMC(double a, double b) { return a / (b * b); }
void IMCT(double t) {
  if (t <= 16.9) {
    printf("Você está muito abaixo do Peso!");
  }

  else if (t <= 18.4) {
    printf("Você está abaixo do peso!");
  }

  else if (t <= 24.9) {
    printf("Você está com peso normal !");
  }

  else if (t <= 29.9) {
    printf("Você está acima do peso");
  }

  else if (t <= 34.9) {
    printf("Você tem obesidade grau I");
  }
}
int main() {
  double altura, peso;

  printf("Insira seu peso(kg) e altura(m)\n");
  scanf("%lf%lf", &peso, &altura);

  printf("Seu IMC é %lf\n", IMC(peso, altura));
  IMCT(IMC(peso, altura));

  return 0;
}