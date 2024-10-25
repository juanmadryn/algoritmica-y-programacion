#include <stdio.h>

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

// Función de ordenamiento por inserción con callback para comparación
void ordenamientoPorInsercion(int arreglo[], int tamanio, int (*comparar)(int, int)) {
    for (int i = 1; i < tamanio; i++) {
        int valorActual = arreglo[i];
        int j = i - 1;
        
        // Usamos la función comparar para decidir el orden
        while (j >= 0 && comparar(arreglo[j], valorActual) > 0) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = valorActual;
        imprimirArreglo(arreglo, tamanio);
    }
}

// Función de comparación para orden ascendente
int compararAscendente(int a, int b) {
    return a - b;
}

// Función de comparación para orden descendente
int compararDescendente(int a, int b) {
    return b - a;
}

int main() {
    int arreglo[] = {4, 7, 1, 2, 6, 8, 3, 5};
    int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);

    // Imprimir arreglo original
    printf("Arreglo original:\n");
    imprimirArreglo(arreglo, tamanio);

    printf("=====================\n");
    printf("Ordenando en forma ascendente:\n");
    ordenamientoPorInsercion(arreglo, tamanio, compararAscendente);
    
    // Volvemos a inicializar el arreglo para otra prueba
    int arreglo2[] = {4, 7, 1, 2, 6, 8, 3, 5};
    
    printf("=====================\n");
    printf("Ordenando en forma descendente:\n");
    ordenamientoPorInsercion(arreglo2, tamanio, compararDescendente);

    return 0;
}
