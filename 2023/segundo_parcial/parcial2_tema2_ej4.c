#include <stdio.h>

int main(int argc, char *argv[]) {
    // Verificar argumentos
    if (argc != 3) {
        printf("Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    //Archivo de origen en modo de lectura
    FILE *archivo_origen = fopen(argv[1], "r");
    if (archivo_origen == NULL) {
        perror("Error al abrir el archivo de origen");
        return 2;
    }

    //Archivo de destino en modo de escritura
    FILE *archivo_destino = fopen(argv[2], "w");
    if (archivo_destino == NULL) {
        perror("Error al abrir el archivo de destino");
        fclose(archivo_origen);
        return 3;
    }

    // Copiar el contenido del archivo de origen al archivo de destino
    int caracter;
    while ((caracter = fgetc(archivo_origen)) != EOF) {
        fputc(caracter, archivo_destino);
    }

    // Cerrar los archivos
    fclose(archivo_origen);
    fclose(archivo_destino);

    printf("El contenido se ha copiado de %s a %s\n", argv[1], argv[2]);

    return 0;
}