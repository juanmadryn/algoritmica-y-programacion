#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char c;

    // Abre el archivo en modo de lectura
    file = fopen(__FILE__, "r"); // __FILE__ es una macro que contiene el nombre del archivo fuente actual

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }

    // Lee y muestra el contenido del archivo
    printf("Contenido del archivo:\n");
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Cierra el archivo
    fclose(file);

    return 0;
}
