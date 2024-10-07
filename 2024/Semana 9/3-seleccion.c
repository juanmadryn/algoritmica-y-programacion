#include <stdio.h>

void intercambiar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void imprimirArreglo(int arreglo[], int tamanio){
    for (int i = 0; i < tamanio; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void ordenamientoPorSeleccion(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < tamanio; j++) {
            if (arreglo[j] < arreglo[minimo]) {
                minimo = j;
            }
        }
        intercambiar(&arreglo[minimo], &arreglo[i]);
        imprimirArreglo(arreglo, tamanio);
    }
}

int main(){
    int arreglo[] = {4,7,1,2,6,8,3,5};
    int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);

    imprimirArreglo(arreglo, tamanio);
    printf("=====================\n");
    ordenamientoPorSeleccion(arreglo, tamanio);
    printf("=====================\n");
    imprimirArreglo(arreglo, tamanio);
}