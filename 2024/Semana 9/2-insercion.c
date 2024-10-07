#include <stdio.h>

void imprimirArreglo(int arreglo[], int tamanio){
    for (int i = 0; i < tamanio; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void ordenamientoPorInsercion(int arreglo[], int tamanio) {
    for (int i = 1; i < tamanio; i++) {
        int valorActual = arreglo[i];
        int j = i - 1;
        
        while (j >= 0 && arreglo[j] > valorActual) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = valorActual;
        imprimirArreglo(arreglo, tamanio);
    }
}

int main(){
    int arreglo[] = {4,7,1,2,6,8,3,5};
    int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);
    
    imprimirArreglo(arreglo, tamanio);
    printf("=====================\n");
    ordenamientoPorInsercion(arreglo, tamanio);
    printf("=====================\n");
    imprimirArreglo(arreglo, tamanio);
}