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

void ordenamientoPorBurbujeo(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        for (int j = 0; j < tamanio - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
        imprimirArreglo(arreglo, tamanio);
    }
}


int main(){
    int arreglo[] = {4,7,1,2,6,8,3,5};
    int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);

    imprimirArreglo(arreglo, tamanio);
    printf("=====================\n");
    ordenamientoPorBurbujeo(arreglo, tamanio);
    printf("=====================\n");
    imprimirArreglo(arreglo, tamanio);
}