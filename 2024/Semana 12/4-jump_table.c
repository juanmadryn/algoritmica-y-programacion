#include <stdio.h>

void caso0() {
    printf("Caso 0 ejecutado\n");
}

void caso1() {
    printf("Caso 1 ejecutado\n");
}

void caso2() {
    printf("Caso 2 ejecutado\n");
}

// Tabla de salto (arreglo de punteros a función)
void (*tablaDeSalto[])() = {caso0, caso1, caso2};

int main() {
    int opcion;

    printf("Elige un caso (0-2): ");
    scanf("%d", &opcion);

    if (opcion >= 0 && opcion <= 2) {
        // Usar la tabla de salto para invocar la función correcta
        tablaDeSalto[opcion]();
    } else {
        printf("Opción inválida.\n");
    }

    return 0;
}
