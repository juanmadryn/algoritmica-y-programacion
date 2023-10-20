#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s nombre_archivo\n", argv[0]);
        return 1;
    }

    FILE *file;
    char c;
    
    // Abre el archivo en modo de lectura
    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }

    // Lee y muestra el contenido del archivo
    printf("Contenido del archivo %s:\n", argv[1]);
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Cierra el archivo
    fclose(file);

    return 0;
}
