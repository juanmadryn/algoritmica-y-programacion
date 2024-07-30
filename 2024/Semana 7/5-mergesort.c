#include <stdio.h>
#include <stdlib.h>

// Función para fusionar dos subarreglos
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionar los arreglos temporales de nuevo en arr[left..right]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = left; // Índice inicial del subarreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria
    free(L);
    free(R);
}


// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Función principal que ordena arr[left..right] usando merge()
void mergeSort(int arr[], int left, int right) {
    printf("=============\n");
    printf("Izquierda: %d - Derecha: %d - Arreglo: ", left, right);
    printArray(&arr[left], right-left+1);
    if (left < right) {
        int mid = left + (right - left) / 2;
        printf("La mitad es %d\n", mid);
        // Ordenar la primera y la segunda mitad
        printf("Mitad izquierda: ");
        printArray(&arr[left], mid-left+1);
        printf("Mitad derecha: ");
        printArray(&arr[mid+1], right-mid);        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Fusionar las dos mitades ordenadas
        merge(arr, left, mid, right);
        printf("Arreglo ordenado: ");
        printArray(&arr[left], right-left+1);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, arr_size);
    return 0;
}
