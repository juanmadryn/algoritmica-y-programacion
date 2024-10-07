#include <stdio.h>
#include <stdlib.h>

#define RUN 32

// Función para realizar Insertion Sort en el subarreglo arr[izq..der]
void insertionSort(int arr[], int izq, int der) {
    for (int i = izq + 1; i <= der; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= izq && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Función auxiliar para el "merge" tradicional de dos subarreglos
// con la optimización de galloping.
void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    int gallopLeft = 7, gallopRight = 7;  // Umbral de galloping

    // Comparación normal con galloping
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
            if (--gallopLeft == 0) {
                while (i < len1 && left[i] <= right[j])
                    arr[k++] = left[i++];
                gallopLeft = 7;
            }
        } else {
            arr[k++] = right[j++];
            if (--gallopRight == 0) {
                while (j < len2 && right[j] <= left[i])
                    arr[k++] = right[j++];
                gallopRight = 7;
            }
        }
    }

    // Copia los elementos restantes de left[]
    while (i < len1)
        arr[k++] = left[i++];

    // Copia los elementos restantes de right[]
    while (j < len2)
        arr[k++] = right[j++];

    free(left);
    free(right);
}

// Función para implementar TimSort
void timSort(int arr[], int n) {
    // Ordenar pequeñas corridas usando Insertion Sort
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, i + RUN - 1 < n - 1 ? i + RUN - 1 : n - 1);
    }

    // Realizar merge de corridas usando el merge modificado con galloping
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1 < n - 1 ? left + 2 * size - 1 : n - 1;

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {5, 21, 7, 23, 19, 10, 2, 1, 9, 15, 8, 6, 3, 12, 4, 11, 18, 14, 16, 20, 13, 17, 22, 24};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, n);

    timSort(arr, n);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);

    return 0;
}
