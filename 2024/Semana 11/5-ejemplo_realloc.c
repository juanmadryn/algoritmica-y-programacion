#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Para usar strcpy

int main() {
    // Caso 1: Asignación inicial de espacio para 6 caracteres (5 + '\0')
    char *cadena = (char *)malloc(6 * sizeof(char));

    if (cadena == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Copiamos la cadena "Hola!" a la memoria asignada
    strcpy(cadena, "Hola!");
    printf("Cadena inicial: %s\n", cadena);

    // Caso 2: Aumentar el espacio para 11 caracteres (10 + '\0')
    cadena = (char *)realloc(cadena, 11 * sizeof(char));
    if (cadena == NULL) {
        printf("Error al aumentar el tamaño de memoria.\n");
        return 1;
    }

    // Agregamos más texto a la cadena
    strcat(cadena, " Mundo");  // Ahora la cadena completa debería ser "Hola! Mundo"
    printf("Cadena después de aumentar el tamaño: %s\n", cadena);

    // Caso 3: Reducir el espacio a 4 caracteres (3 + '\0')
    cadena = (char *)realloc(cadena, 4 * sizeof(char));
    if (cadena == NULL) {
        printf("Error al reducir el tamaño de memoria.\n");
        return 1;
    }

    // Después de reducir el tamaño, el contenido de la cadena es impredecible
    printf("Cadena después de reducir el tamaño: %s\n", cadena);

    strcpy(cadena, "Chau!");

    printf("Cadena después de cambiar el contenido: %s\n", cadena);

    // Liberar la memoria asignada
    free(cadena);

    return 0;
}
