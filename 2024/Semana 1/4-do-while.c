#include <stdio.h>

int main() {
    int numero;

    do {
        printf("Ingrese un número positivo (ingrese un número negativo para salir): ");
        scanf("%d", &numero);

        if (numero >= 0) {
            printf("Número ingresado: %d\n", numero);
        }
    } while (numero >= 0); // Continúa pidiendo números mientras el número ingresado sea positivo

    printf("Número negativo ingresado. Salida del programa.\n");

    return 0;
}
