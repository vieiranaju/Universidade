#include <stdio.h>
#include <math.h>

// Função para calcular o valor da curvatura kappa(t)
double curvature(double t) {
    // Componentes de r'(t)
    double a1 = 16 * M_PI * cos(4 * M_PI * t) + 40;
    double a2 = 4 * M_PI * cos(4 * M_PI * t) - 980 * t;

    // Componentes de r''(t)
    double b1 = -64 * M_PI * M_PI * sin(4 * M_PI * t);
    double b2 = -16 * M_PI * M_PI * sin(4 * M_PI * t) - 980;

    // Produto vetorial (z-component)
    double cross_product_z = a1 * b2 - a2 * b1;

    // Norma de r'(t)
    double norm_r1 = sqrt(a1 * a1 + a2 * a2);

    // Curvatura kappa(t)
    double kappa = fabs(cross_product_z) / pow(norm_r1, 3);

    return kappa;
}

int main() {
    double t;
    printf("Digite o valor de t: ");
    scanf("%lf", &t);

    double kappa = curvature(t);
    printf("A curvatura kappa(%lf) é: %lf\n", t, kappa);

    return 0;
}