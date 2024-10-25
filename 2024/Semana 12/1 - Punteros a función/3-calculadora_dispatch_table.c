#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

// Dispatch table (arreglo de punteros a función)
int (*operaciones[])(int, int) = {sumar, restar, multiplicar};

int main() {
    int x = 10, y = 5;
    int opcion;

    printf("Selecciona una operación: 0=Sumar, 1=Restar, 2=Multiplicar: ");
    scanf("%d", &opcion);

    if (opcion >= 0 && opcion <= 2) {
        // Llamada a la función adecuada desde la tabla de despacho
        printf("Resultado: %d\n", operaciones[opcion](x, y));
    } else {
        printf("Opción inválida.\n");
    }

    return 0;
}
