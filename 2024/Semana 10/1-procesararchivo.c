#include <stdio.h>

int main() {
    FILE *archivo;
    char c;

    // Abrir el archivo en modo lectura ("r")
    archivo = fopen("archivo.txt", "r");

    // Verificar si el archivo se pudo abrir correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;  // Salir del programa si hay un error
    }

    // Leer el contenido del archivo carácter por carácter y mostrarlo en pantalla
    while ((c = fgetc(archivo)) != EOF) {
        printf("%c", c);
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}
