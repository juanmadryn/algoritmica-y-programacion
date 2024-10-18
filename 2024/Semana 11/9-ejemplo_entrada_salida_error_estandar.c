#include <stdio.h>

int main() {
    int numero;
    printf("Ingresa un número: ");
    
    if (scanf("%d", &numero) != 1) {
        fprintf(stderr, "Error: entrada no válida.\n"); // Mensaje de error a stderr
        return 1; // Código de error
    }

    printf("Has ingresado: %d\n", numero); // Mensaje a stdout
    return 0;
}
