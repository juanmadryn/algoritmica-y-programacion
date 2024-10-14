#include <stdio.h>
#include <stdlib.h>  // Para usar malloc

int main() {
    // Declaración y asignación de un arreglo de caracteres
    char arreglo[] = "Hola mundo";
    
    // Declaración y asignación de un puntero a caracteres (cadena literal)
    char *puntero_literal = "Hola mundo";

    // Asignación dinámica de memoria para un puntero con malloc
    char *puntero_malloc = (char *)malloc(11 * sizeof(char));
    if (puntero_malloc == NULL) {
        printf("Error al asignar memoria.\n");
        return 1; // Terminar el programa si malloc falla
    }

    // Copiar la cadena "Hola mundo" al área de memoria asignada dinámicamente
    for (int i = 0; i < 11; i++) {
        puntero_malloc[i] = "Hola mundo"[i];  // Copia caracter por caracter
    }

    // Mostrar los valores
    printf("Arreglo de caracteres: %s\n", arreglo);
    printf("Puntero a cadena literal: %s\n", puntero_literal);
    printf("Puntero asignado con malloc: %s\n", puntero_malloc);

    // Modificar el contenido del arreglo de caracteres
    arreglo[0] = 'h';
    
    // Intento de modificar la cadena literal
    puntero_literal[0] = 'h';

    // Modificar el contenido de la memoria asignada dinámicamente
    puntero_malloc[0] = 'h';

    // Mostrar los resultados después de las modificaciones
    printf("Arreglo modificado: %s\n", arreglo);
    printf("Puntero malloc modificado: %s\n", puntero_malloc);

    // Liberar la memoria asignada con malloc
    free(puntero_malloc);

    return 0;
}
