#include <stdio.h>

int main() {
    int numero;
    printf("Ingresa un número: ");
    
    if (scanf("%d", &numero) != 1) {
        fprintf(stderr, "Error: entrada no válida.\n");
        return 1;
    }

    printf("Has ingresado: %d\n", numero);
    return 0;
}
