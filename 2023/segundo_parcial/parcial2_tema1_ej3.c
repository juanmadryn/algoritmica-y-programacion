#include <stdio.h>

void ordenar(float arreglo[], int longitud) {
    int i, j;

    for (i = 0; i < longitud - 1; i++) {
        for (j = 0; j < longitud - i - 1; j++) {
            // si el elemento en la posición j es mayor que el que le sigue, tengo que intercambiarlos
            if (arreglo[j] > arreglo[j + 1]) {
                float temp = arreglo[j];
                arreglo[j] =  arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

int main() {
    float numeros[] = {5.2, 1.8, 9.3, 3.7, 2.1};
    int longitud = sizeof(numeros) / sizeof(numeros[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < longitud; i++) {
        printf("%.2f ", numeros[i]);
    }

    ordenar(numeros, longitud);

    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < longitud; i++) {
        printf("%.2f ", numeros[i]);
    }

    return 0;
}