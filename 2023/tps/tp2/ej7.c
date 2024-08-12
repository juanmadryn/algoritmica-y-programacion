#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 20
#define NUM_STRINGS 10

// Función para imprimir el arreglo de cadenas
void imprimirArreglo(char arr[NUM_STRINGS][MAX_STR_LEN], int n) {
    printf("Arreglo de cadenas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char arreglo[NUM_STRINGS][MAX_STR_LEN];
    int numCadenas = 0;

    printf("Inserte cadenas en orden alfabético (ingrese 'fin' para salir).\n");

    while (1) {
        char nuevaCadena[MAX_STR_LEN];
        printf("Ingrese una cadena: ");
        scanf("%s", nuevaCadena);

        if (strcmp(nuevaCadena, "fin") == 0) {
            break;  // Salir del bucle si se ingresa "fin"
        }

        // Buscar la posición donde insertar la nueva cadena en orden alfabético
        int i;
        for (i = numCadenas - 1; i >= 0; i--) {
            if (strcmp(nuevaCadena, arreglo[i]) > 0) {
                break;
            }
        }

        // Desplazar las cadenas para hacer espacio para la nueva cadena
        for (int j = numCadenas - 1; j > i; j--) {
            strcpy(arreglo[j], arreglo[j - 1]);
        }

        // Insertar la nueva cadena en la posición adecuada
        strcpy(arreglo[i + 1], nuevaCadena);

        // Incrementar el contador de cadenas
        numCadenas++;

        // Si el arreglo está lleno, quitar la última cadena
        if (numCadenas > NUM_STRINGS) {
            numCadenas--;
        }

        // Imprimir el arreglo en su nuevo estado
        imprimirArreglo(arreglo, numCadenas);
    }

    printf("Programa finalizado.\n");

    return 0;
}
