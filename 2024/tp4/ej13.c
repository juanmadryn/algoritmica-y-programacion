/*Revise el programa del ejercicio E11TP2 y proponga al menos tres funciones que podría extraer
 del código. Determine la declaración de las funciones indicando tipo de retorno,
 nombre y parámetros de entrada con sus tipos. Si lo desea, implemente las funciones.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CADENAS 1000
#define MAX_LONGITUD 30

// Función para agregar palabra al diccionario
void agregarPalabra(char diccionario[MAX_CADENAS][MAX_LONGITUD], int *cantidad, char *palabra) {
    strcpy(diccionario[*cantidad], palabra);
    (*cantidad)++;
}

// Función para imprimir el diccionario
void imprimirDiccionario(char diccionario[MAX_CADENAS][MAX_LONGITUD], int cantidad) {
    printf("Estado actual del diccionario:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", diccionario[i]);
    }
    printf("\n");
}

// Función para buscar palabra en el diccionario
int buscarPalabra(char diccionario[MAX_CADENAS][MAX_LONGITUD], int cantidad, char *palabra) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(diccionario[i], palabra) == 0) {
            return 1; // Palabra encontrada
        }
    }
    return 0; // Palabra no encontrada
}

int main() {
    char diccionario[MAX_CADENAS][MAX_LONGITUD];
    int cantidad = 0;

    int continuar = 1;
    while (continuar) {
        char oracion[MAX_LONGITUD * 10];
        printf("Ingrese una oracion (o 'fin' para terminar): ");
        fgets(oracion, sizeof(oracion), stdin);
        oracion[strcspn(oracion, "\n")] = 0;

        if (strcmp(oracion, "fin") == 0) {
            continuar = 0;
        } else {
            char *palabra = strtok(oracion, " ");
            while (palabra != NULL) {
                if (!buscarPalabra(diccionario, cantidad, palabra)) {
                    printf("La palabra '%s' no esta en el diccionario. Desea agregarla? (s/n): ", palabra);
                    char respuesta;
                    scanf(" %c", &respuesta);
                    getchar(); // Limpiar buffer de entrada
                    if (respuesta == 's') {
                        agregarPalabra(diccionario, &cantidad, palabra);
                    } else {
                        printf("\nPalabra no agregada\n");
                    }
                }

                palabra = strtok(NULL, " ");
            }
        }

        imprimirDiccionario(diccionario, cantidad);
    }
    return 0;
}
