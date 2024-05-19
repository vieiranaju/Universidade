#include <stdio.h>
#include <math.h>

int main(){
 
float Salario;

printf("Insira o salario atual: ");

scanf("%f", &Salario);
if (Salario <= 1000){
        Salario = Salario*1.15;
    
}
else if(Salario<=2000){
        Salario = Salario*1.10;
}
else{
        Salario = Salario*1.05;
}

printf("O salario final é: %.2f\n\n\n", Salario);
    
float VeloVeiculo, LimiteVia, diferenca;
float multa = 0;
int pontos = 0;

    printf("\n\nInsira a velocidade do veiculo e a maxima permitida na rodovia: \n\n");

    scanf("%f%f", &VeloVeiculo, &LimiteVia);
    diferenca = VeloVeiculo/LimiteVia;

    if(diferenca>1){
        if(diferenca<= 1.2){
            multa = 130.35;
            pontos = 4;
        }

        else if(diferenca<= 1.5){
            multa = 195.23;
            pontos = 5;
        }

        else{
            multa = 880.65;
            pontos = 7;
        }
    }

    printf("\n%.2f\n%i\n\n\n", multa, pontos);

    int x;

    printf("\n\nInsira um valor: \n\n");
    scanf("%i", &x);

    if (x>=0){
        if(x%2==0){
            printf("Positivo e Par!");
        }
        else{
            printf("Positivo e Impar!");
        }
    }

    else{
        if(x%2==0){
            printf("Negativo e Par!");
        }
        else{
            printf("Negativo e Impar!");
        }
    }

    return 0;

}