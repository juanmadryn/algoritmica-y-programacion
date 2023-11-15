#include <stdio.h>
#include <string.h>

// Función de comparación
int comparar(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Búsqueda binaria
int buscarCadena(char arr[][50], int tamanio, char cadena[]) {
    
    int izquierda = 0;
    int derecha = tamanio - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Comparar la cadena con el elemento en la posición media
        int comparacion = comparar(arr[medio], cadena);

        // Si encontramos la cadena, devolver la posición
        if (comparacion == 0) {
            return medio;
        }
        // Si la cadena está en la mitad izquierda, ajustar la derecha
        else if (comparacion > 0) {
            derecha = medio - 1;
        }
        // Si la cadena está en la mitad derecha, ajustar la izquierda
        else {
            izquierda = medio + 1;
        }
    }

    // Si no se encontró la cadena, devolver -1
    return -1;
}

int main(int argc, char ** argv) {
    if(argc < 2){
        printf("Uso: programa palabra_buscada");
        return -1;
    }

    char cadenas[][50] = {"apple", "banana", "cherry", "date", "grape", "orange", "pear"};
    int tamanio = sizeof(cadenas) / sizeof(cadenas[0]);
    char * cadenaBuscada = argv[1];

    int resultado = buscarCadena(cadenas, tamanio, cadenaBuscada);

    if (resultado != -1) {
        printf("La cadena \"%s\" se encuentra en la posición %d.\n", cadenaBuscada, resultado);
    } else {
        printf("La cadena \"%s\" no se encontró en el arreglo.\n", cadenaBuscada);
    }

    return 0;
}