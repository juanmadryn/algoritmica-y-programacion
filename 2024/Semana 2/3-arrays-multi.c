#include <stdio.h>

int main() {
    // Declaración e inicialización estática de un arreglo de flotantes
    // que representa los pesos de 100 pasajeros, incluyendo algunos niños.
    float pesosPasajeros[17][6] = {
        {72.5, 68.0, 80.2, 90.1, 55.3, 60.7},
        {74.9, 66.4, 85.0, 92.5, 70.3, 64.2}, 
        {78.1, 33.8, 60.0, 95.2, 31.2, 69.7}, 
        {72.0, 89.9, 74.3, 77.5, 83.2, 61.5}, 
        {58.6, 71.9, 68.7, 85.3, 79.4, 87.6}, 
        {90.4, 82.3, 75.1, 66.2, 92.7, 88.9}, 
        {73.0, 69.3, 80.5, 59.1, 26.4, 38.0}, 
        {29.5, 70.8, 75.9, 76.4, 78.5, 84.7}, 
        {82.0, 68.9, 30.7, 73.8, 90.0, 64.8}, 
        {81.0, 77.0, 67.2, 83.5, 87.0, 71.3}, 
        {69.9, 89.1, 74.2, 78.9, 85.1, 65.4}, 
        {63.5, 86.7, 91.0, 79.7, 62.8, 76.3}, 
        {35.2, 88.2, 80.3, 82.7, 73.5, 75.7}, 
        {90.5, 81.2, 84.9, 69.1, 77.8, 70.1}, 
        {79.2, 74.6, 64.3, 71.0, 66.7, 87.8},
        {67.9, 28.5, 42.3, 72.6, 91.3, 88.0}, 
        {70.0}
    };

    float pesoTotal = 0.0;
    float pesoPorFila[17] = {0}; // Arreglo para almacenar el peso total por fila

    // Calcular el peso total por fila y el peso total de todos los pasajeros
    for(int i = 0; i < 17; i++) {
        for(int j = 0; j < 6; j++) {
            pesoTotal += pesosPasajeros[i][j];
            pesoPorFila[i] += pesosPasajeros[i][j];
        }
    }

    // Imprimir el peso total por fila
    for(int i = 0; i < 17; i++) {
        printf("Peso total de la fila %d: %.2f kg\n", i + 1, pesoPorFila[i]);
    }

    // Imprimir el peso total
    printf("El peso total de los 100 pasajeros es: %.2f kg\n", pesoTotal);

    return 0;
}
