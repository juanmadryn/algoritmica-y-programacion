#include <stdio.h>
#include <string.h>

int main() {
    char nombre[10] = "Juan Manuel";

    printf("Nombre: %s\n", nombre);
    printf("Longitud: %zu\n", strlen(nombre));

    return 0;
}
