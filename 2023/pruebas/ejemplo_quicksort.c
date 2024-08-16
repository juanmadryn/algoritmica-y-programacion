#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para el ordenamiento por burbujeo
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Función para particionar el arreglo y seleccionar el pivote
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Función para fusionar dos subarreglos de arr[]
// El primer subarreglo es arr[l..m]
// El segundo subarreglo es arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Fusionar los arreglos temporales de vuelta en arr[l..r]
    i = 0;
    j = 0;
    k = l;
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

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Igual que (l+r)/2, pero evita el desbordamiento para l y r grandes
        int m = l + (r - l) / 2;

        // Ordenar las dos mitades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusionar las mitades ordenadas
        merge(arr, l, m, r);
    }
}

int main() {
    // Semilla para generar números aleatorios
    srand(time(NULL));

    // Tamaño del arreglo
    int n = 100000;

    // Crear un arreglo de 1 millón de números aleatorios
    int *arr_quicksort = (int *)malloc(n * sizeof(int));
    int *arr_bubblesort = (int *)malloc(n * sizeof(int));
    int *arr_mergesort = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int random_num = rand() % 10000 + 1;;
        arr_quicksort[i] = arr_bubblesort[i] = arr_mergesort[i] = random_num;
    }
    printf("Primer elemento del arreglo: %d\n", arr_quicksort[0]);
    printf("Último elemento del arreglo: %d\n", arr_quicksort[n-1]);


    // Obtener el tiempo de inicio para Quicksort
    clock_t start_time_quicksort = clock();

    // Aplicar Quicksort
    quicksort(arr_quicksort, 0, n - 1);

    // Obtener el tiempo de finalización para Quicksort
    clock_t end_time_quicksort = clock();

    // Calcular el tiempo total de ejecución para Quicksort
    double execution_time_quicksort = ((double)end_time_quicksort - start_time_quicksort) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución (Quicksort): %f segundos\n", execution_time_quicksort);
    printf("Primer elemento del arreglo: %d\n", arr_quicksort[0]);
    printf("Último elemento del arreglo: %d\n", arr_quicksort[n-1]);
    // Obtener el tiempo de inicio para el ordenamiento por burbujeo
    clock_t start_time_bubblesort = clock();

    // Aplicar el ordenamiento por burbujeo
    bubbleSort(arr_bubblesort, n);

    // Obtener el tiempo de finalización para el ordenamiento por burbujeo
    clock_t end_time_bubblesort = clock();

    // Calcular el tiempo total de ejecución para el ordenamiento por burbujeo
    double execution_time_bubblesort = ((double)end_time_bubblesort - start_time_bubblesort) / CLOCKS_PER_SEC;

    // Imprimir los tiempos de ejecución
    printf("Tiempo de ejecución (Bubblesort): %f segundos\n", execution_time_bubblesort);
    printf("Primer elemento del arreglo: %d\n", arr_bubblesort[0]);
    printf("Último elemento del arreglo: %d\n", arr_bubblesort[n-1]);

    // Obtener el tiempo de inicio para Merge Sort
    clock_t start_time_mergesort = clock();

    // Aplicar Merge Sort
    mergeSort(arr_mergesort, 0, n - 1);

    // Obtener el tiempo de finalización para Merge Sort
    clock_t end_time_mergesort = clock();

    // Calcular el tiempo total de ejecución para Merge Sort
    double execution_time_mergesort = ((double)end_time_mergesort - start_time_mergesort) / CLOCKS_PER_SEC;

    // Imprimir los tiempos de ejecución
    printf("Tiempo de ejecución (Mergesort): %f segundos\n", execution_time_mergesort);
    printf("Primer elemento del arreglo: %d\n", arr_mergesort[0]);
    printf("Último elemento del arreglo: %d\n", arr_mergesort[n-1]);

    // Liberar la memoria de los arreglos
    free(arr_quicksort);
    free(arr_bubblesort);
    free(arr_mergesort);


    return 0;
}