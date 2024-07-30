#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para pausar la ejecución y esperar la entrada del usuario
void pause() {
    printf("Presiona Enter para continuar...\n");
    getchar();
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1); // Elección aleatoria del pivote
    int pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]); // Mover pivote al final
    int i = low - 1;

    printf("Particionando con pivote %d (originalmente en posición %d):\n", pivot, pivotIndex);
    printArray(arr, high - low + 1);
    pause();

    // Recorro todo el arreglo
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            // Muevo a la izquierda los elementos menores al pivot
            i++;
            swap(&arr[i], &arr[j]);
            printf("Intercambiando %d y %d:\n", arr[i], arr[j]);
            printArray(arr, high - low + 1);
            pause();
        }
    }
    swap(&arr[i + 1], &arr[high]); // Mover pivote a su posición final
    printf("Pivote %d colocado en posición %d:\n", pivot, i + 1);
    printArray(arr, high - low + 1);
    pause();
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiono y tomo la ubicación final del pivot
        int pi = partition(arr, low, high);
        // Repito para subarreglo a la izquierda del pivot...
        quickSort(arr, low, pi - 1);
        // ... y para subarreglo a la derecha del pivot
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL)); // Inicializar semilla de random

    int arr[] = {29, 3, 14, 37, 14, 13, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}
