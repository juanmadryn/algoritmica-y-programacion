#include <stdio.h>

int contarLineas(char *nombreArchivo) {
    FILE *archivo;
    int contador = 0;
    char caracter;

    // Archivo en modo lectura
    archivo = fopen(nombreArchivo, "r");

    // Verificar
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return -1; 
    }

    // Contar el número de líneas, escencialmente cuento la cantidad de saltos de línea
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            contador++;
        }
    }

    if (caracter != '\n' && contador > 0) {
        contador++;
    }

    // Cerrar el archivo
    fclose(archivo);

    return contador;
}

int main() {
    char nombreArchivo[] = "archivo.txt";

    int numeroDeLineas = contarLineas(nombreArchivo);

    if (numeroDeLineas >= 0) {
        printf("El archivo %s tiene %d líneas.\n", nombreArchivo, numeroDeLineas);
    } else {
        printf("Error al contar las líneas del archivo %s.\n", nombreArchivo);
    }

    return 0;
}