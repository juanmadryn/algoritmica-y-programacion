#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numero;
    char entrada[100]; // Para almacenar la entrada del usuario como texto

    while (scanf("%d", &numero) == 1) {
        int duplicado = numero * 2;
        printf("%d\n", duplicado);

        // Limpiamos el búfer de entrada para evitar problemas con futuras lecturas
        fgets(entrada, sizeof(entrada), stdin);
    }

    return 0;
}