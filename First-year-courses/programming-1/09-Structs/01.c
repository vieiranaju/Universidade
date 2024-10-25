#include <stdio.h>
#include <math.h>

struct ponto {
	float x;
	float y;
};

float distancia(struct ponto p, struct ponto p1) {
	float dist;
	dist = sqrt(pow((p1.x - p.x), 2) + pow((p1.y - p.y), 2));
	return dist;
}

int main() {
	struct ponto p, p1;
	float dist;

	printf("Digite as coordenadas do primeiro ponto (x y): ");
	scanf("%f %f", &p.x, &p.y);

	printf("Digite as coordenadas do segundo ponto (x y): ");
	scanf("%f %f", &p1.x, &p1.y);

	dist = distancia(p, p1);
	printf("A distancia entre os pontos { %.1f , %.1f } e { %.1f , %.1f } eh %.1f\n", p.x, p.y, p1.x, p1.y, dist);

	return 0;
}