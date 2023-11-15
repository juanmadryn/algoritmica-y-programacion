#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char c;

    // Abre el archivo __FILE__ (el fuente actual) en modo de lectura
    file = fopen(__FILE__, "r");

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }

    // Muestra el contenido del archivo
    printf("Contenido del archivo:\n");
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Cierra el archivo
    fclose(file);

    return 0;
}
