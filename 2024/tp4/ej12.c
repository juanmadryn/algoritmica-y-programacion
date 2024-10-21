/*
Modificá el programa del ejercicio E9TP2 para que reciba como parámetro un arreglo de cadenas de caracteres
y una cadena de caracteres adicional y devuelva el arreglo del primer parámetro con la cadena del segundo 
insertada en orden alfabético.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CADENAS 10
#define MAX_LONGITUD 20

// Función para insertar una cadena en orden alfabético
void insertarCadena(char arreglo[MAX_CADENAS][MAX_LONGITUD], int *cantidad, char *nueva) {
    int indice;

    // Buscar posición para insertar la nueva cadena
    for (indice = 0; indice < *cantidad && strcmp(arreglo[indice], nueva) < 0; indice++)
        ;

    // Desplazar cadenas para hacer lugar
    if (*cantidad < MAX_CADENAS || indice < *cantidad) {
        for (int i = *cantidad - 1; i >= indice; i--) {
            strcpy(arreglo[i + 1], arreglo[i]);
        }

        // Insertar la nueva cadena
        strcpy(arreglo[indice], nueva);

        // Actualizar cantidad
        if (*cantidad < MAX_CADENAS) {
            (*cantidad)++;
        } else {
            *cantidad = MAX_CADENAS;
        }
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(char arreglo[MAX_CADENAS][MAX_LONGITUD], int cantidad) {
    printf("Arreglo actual:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", arreglo[i]);
    }
}

int main() {
    char arreglo[MAX_CADENAS][MAX_LONGITUD];
    int cantidad = 0;
    char nueva[MAX_LONGITUD];

    while (1) {
        printf("Ingrese una cadena (o 'fin' para terminar): ");
        scanf("%19s", nueva);

        if (strcmp(nueva, "fin") == 0) {
            break;
        }

        insertarCadena(arreglo, &cantidad, nueva);
        imprimirArreglo(arreglo, cantidad);
    }

    return 0;
}