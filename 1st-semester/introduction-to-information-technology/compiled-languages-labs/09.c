#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, x, y, z, w, dist, distMin;
    int classeR, classe, classeP, acerto = 0;

    FILE *arquivoTeste = fopen("IrisTeste.txt", "r");
    // abre o arquivo IrisTeste

    while (!feof(arquivoTeste)) {
        // Continua realizando até finalizar a leitura do arquivo
        fscanf(arquivoTeste, "%f,%f,%f,%f,%d", &a, &b, &c, &d, &classeR);
        // lê e recebe os dados do arquivo
        distMin = 10000000;

        FILE *arquivoTreino = fopen("IrisTreino.txt", "r");
        // abre o arquivo IrisTreino

        while (!feof(arquivoTreino)) {
            // realiza a verificação de cada linha do arquivo de treino
            // para encontrar a que se encontra mais próxima e poder prever a classe que se encontra a folha
            fscanf(arquivoTreino, "%f,%f,%f,%f,%d", &x, &y, &z, &w, &classe);
            dist = sqrt((x - a) * (x - a) + (y - b) * (y - b) + (z - c) * (z - c) + (w - d) * (w - d));
            // cálculo do tamanho da folha para a classificação
            
            if (dist < distMin) {
                // verifica a distância mais próxima entre o arquivo de teste e o treino
                // e armazena a classe
                distMin = dist;
                classeP = classe;
            }
        }

        fclose(arquivoTreino); // fecha o arquivo de treino

        if (classeP == classeR) {
            acerto++;
            // conferir a probabilidade de acertos
        }
    }

    fclose(arquivoTeste);
    printf("\n%d", acerto); // mostra o resultado

    return 0;
}
