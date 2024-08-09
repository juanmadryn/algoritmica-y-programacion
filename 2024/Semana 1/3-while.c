#include <stdio.h>

int main() {
    int i = 1;
    int iteraciones;

    printf("Ingrese la cantidad de iteraciones: ");
    scanf("%d", &iteraciones); // Lee la cantidad de iteraciones del usuario

    while (i <= iteraciones) { // El bucle continúa mientras i sea menor o igual a iteraciones
        printf("%d\n", i); // Imprime el valor de i
        i++; // Incrementa el valor de i en 1
    }

    return 0;
}
