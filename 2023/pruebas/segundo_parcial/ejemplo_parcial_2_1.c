#include <stdio.h>

int suma_recursiva(int arr[], int tamanio) {
    // Caso base: si el tamaño es 0, la suma es 0
    if (tamanio == 0) {
        return 0;
    } else {
        // Llamada recursiva: la suma es el elemento actual más la suma del resto del arreglo
        return arr[tamanio - 1] + suma_recursiva(arr, tamanio - 1);
    }
}

int main() {
    // Ejemplo de uso
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);

    // Llamada a la función suma_recursiva
    int resultado = suma_recursiva(arreglo, tamanio);

    // Mostrar el resultado
    printf("La suma de los elementos del arreglo es: %d\n", resultado);

    return 0;
}