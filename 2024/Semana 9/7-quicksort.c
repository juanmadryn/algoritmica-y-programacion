#include <stdio.h>

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para seleccionar el pivote como el elemento del medio
int partition(int arr[], int low, int high) {
    // Elegimos el elemento del medio como pivote
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    printf("%d, %d, %d, %d\n", low, high, mid, pivot);

    // Mover el pivote al final temporalmente para facilitar el particionado
    swap(&arr[mid], &arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            printf("i: %d, j: %d\n", i, j);
            swap(&arr[i], &arr[j]);
        }
    }

    // Colocar el pivote en su posición correcta
    swap(&arr[i + 1], &arr[high]);
    printArray(arr, 8);
    return (i + 1);  // Devolver la posición del pivote
}

// Función recursiva de QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particionar el arreglo y obtener el índice del pivote
        int pi = partition(arr, low, high);

        // Ordenar recursivamente las sublistas
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Programa principal
int main() {
    int arr[] = {4, 7, 1, 3, 8, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}
