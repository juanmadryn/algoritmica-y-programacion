#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarArchivo(char archivo1[], char archivo2[]);

int main(int argc, char *argv[]) {
    // Verificar si se proporcionan los nombres de los archivos como argumentos
    if (argc != 3) {
        printf("Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    char archivo1[20], archivo2[20];

    strcpy(archivo1, argv[1]);
    strcpy(archivo2, argv[2]);
    copiarArchivo(archivo1, archivo2);
    return 0;
}

void copiarArchivo(char archivo1[], char archivo2[]){
    // Abrir el archivo de origen en modo de lectura
    printf("%s", archivo1);
    printf("%s", archivo2);
    FILE *archivo_origen = fopen(archivo1, "r");
    if (archivo_origen == NULL) {
        perror("Error al abrir el archivo de origen");
        return;
    }

    // Abrir el archivo de destino en modo de escritura
    FILE *archivo_destino = fopen(archivo2, "w");
    if (archivo_destino == NULL) {
        perror("Error al abrir el archivo de destino");
        fclose(archivo_origen);
        return;
    }

    // Copiar el contenido del archivo de origen al archivo de destino
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo_origen) != NULL) {
        printf("linea: %s", linea);
        fputs(linea, archivo_destino);
    }

    // Cerrar los archivos
    fclose(archivo_origen);
    fclose(archivo_destino);

    printf("El contenido se ha copiado de %s a %s\n", archivo1, archivo2);
}