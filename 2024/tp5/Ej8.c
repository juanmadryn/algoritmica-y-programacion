/*
Escribí un programa invierta los elementos de un arreglo
de enteros utilizando recursividad.
*/

#include <stdio.h>

// Función recursiva para invertir arreglo
void invertirArreglo(int arreglo[], int inicio, int fin) {
    int temporal;
    
    // Caso base: inicio >= fin
    if (inicio >= fin) {
        return;
    }
    
    // Intercambiar elementos
    temporal = arreglo[inicio];
    arreglo[inicio] = arreglo[fin];
    arreglo[fin] = temporal;
    
    // Llamar recursivamente
    invertirArreglo(arreglo, inicio + 1, fin - 1);
}

// Función para imprimir arreglo
void imprimirArreglo(int arreglo[], int tamaño) {
    int i;
    for (i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int tamaño;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tamaño);
    
    int arreglo[tamaño];
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < tamaño; i++) {
        scanf("%d", &arreglo[i]);
    }
    
    printf("Arreglo original: ");
    imprimirArreglo(arreglo, tamaño);
    
    invertirArreglo(arreglo, 0, tamaño - 1);
    
    printf("Arreglo invertido: ");
    imprimirArreglo(arreglo, tamaño);
    
    return 0;
}