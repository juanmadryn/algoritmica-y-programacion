#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int peso;
    int valor;
    double ratio;
} Objeto;

int comparar(const void* a, const void* b) {
    Objeto* objA = (Objeto*)a;
    Objeto* objB = (Objeto*)b;
    if (objB->ratio > objA->ratio) return 1;
    if (objB->ratio < objA->ratio) return -1;
    return 0;
}

double mochilaFraccionaria(Objeto objetos[], int n, int capacidad) {
    qsort(objetos, n, sizeof(Objeto), comparar);
    double valorTotal = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacidad >= objetos[i].peso) {
            valorTotal += objetos[i].valor;
            capacidad -= objetos[i].peso;
        } else {
            valorTotal += objetos[i].valor * ((double)capacidad / objetos[i].peso);
            break;
        }
    }

    return valorTotal;
}

int main() {
    int n = 3;
    int capacidad = 50;

    // Lista de objetos {peso, valor}
    Objeto objetos[] = {
        {20, 100, 0.0},
        {30, 120, 0.0},
        {10, 60, 0.0}
    };

    // Calcula el ratio valor/peso para cada objeto
    for (int i = 0; i < n; i++) {
        objetos[i].ratio = (double)objetos[i].valor / objetos[i].peso;
    }

    double valorMaximo = mochilaFraccionaria(objetos, n, capacidad);
    printf("Valor máximo en la mochila fraccionaria: %.2f\n", valorMaximo);

    return 0;
}
