#include <stdio.h>
#include <stdlib.h>

// Función para fusionar dos subarreglos ordenados
void merge(int arr[], int left, int mid, int right) {
    int leftSideSize = mid - left + 1;  // Tamaño del subarreglo izquierdo
    int rightSideSize = right - mid;     // Tamaño del subarreglo derecho

    // Crear arreglos temporales para almacenar los datos
    int *L = (int *)malloc(leftSideSize * sizeof(int));
    int *R = (int *)malloc(rightSideSize * sizeof(int));

    // Copiar los datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < leftSideSize; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < rightSideSize; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionar los subarreglos de nuevo en arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < leftSideSize && j < rightSideSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < leftSideSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < rightSideSize) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar la memoria de los arreglos temporales
    free(L);
    free(R);
}

// Función recursiva que implementa Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontrar el punto medio
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, arr_size);

    return 0;
}
