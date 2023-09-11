#include <stdio.h>

#define VECTOR_SIZE 5

int main() {
    int vector[VECTOR_SIZE];
    int escalar;

    printf("Ingrese los %d elementos del vector:\n", VECTOR_SIZE);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("Ingrese el escalar para el producto del vector: ");
    scanf("%d", &escalar);

    printf("Vector original:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    printf("Escalar: %d\n", escalar);

    printf("Vector resultante (producto por escalar):\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        int producto = vector[i] * escalar;
        printf("%d ", producto);
    }
    printf("\n");

    return 0;
}