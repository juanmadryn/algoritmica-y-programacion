#include <stdio.h>

// Función de búsqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int tamanio, int x) {
    if (tamanio == 0) {
        return -1;
    }
    int  medio = tamanio / 2;

    if(arr[medio] == x){
        return medio;
    }

    if(arr[medio] > x){
        return busquedaBinariaRecursiva(arr, medio, x);
    }
    return busquedaBinariaRecursiva(&arr[medio], medio, x);
}

// Función principal
int main() {
    // Ejemplo de uso
    int arreglo[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);
    int objetivo = 5;

    // Llamada a la función de búsqueda binaria recursiva
    int resultado = busquedaBinariaRecursiva(arreglo, tamanio, objetivo);

    // Mostrar el resultado
    if (resultado != -1) {
        printf("El elemento %d se encuentra en la posición %d.\n", objetivo, resultado);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", objetivo);
    }

    return 0;
}
