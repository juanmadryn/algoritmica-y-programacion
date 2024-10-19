/* Escribí un programa con subrutinas que lea una frase ingresada por el usuario (máximo 100 caracteres)
 y luego permita ingresar un número de palabra (según su ubicación en la frase comenzando desde 1) y una
 nueva palabra que la reemplace. El programa modificará la frase original, buscando la palabra en la
 posición indicada y reemplazandola por la nueva, imprimiendo luego la frase modificada. El programa termina
 cuando el usuario ingresa la posición 0. */
 
#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 100

// Función para leer una frase del usuario
void leerFrase(char frase[]) {
    printf("Ingrese una frase (max. 100 caracteres): ");
    fgets(frase, sizeof(char)*MAX_CARACTERES, stdin);
}

// Función para dividir la frase en palabras
void dividirFrase(char frase[], char palabras[][MAX_CARACTERES], int *cantidad) {
    char copiaFrase[MAX_CARACTERES];
    strcpy(copiaFrase, frase);
    char *palabra = strtok(copiaFrase, " ");
    *cantidad = 0;
    while (palabra != NULL) {
        strcpy(palabras[*cantidad], palabra);
        (*cantidad)++;
        palabra = strtok(NULL, " ");
    }
}

// Función para reemplazar una palabra en la frase
void reemplazarPalabra(char palabras[][MAX_CARACTERES], int cantidad, int posicion, char nueva[]) {
    if (posicion >= 1 && posicion <= cantidad) {
        strcpy(palabras[posicion - 1], nueva);
    } else {
        printf("Posicion invalida.\n");
    }
}

// Función para imprimir la frase modificada
void imprimirFrase(char palabras[][MAX_CARACTERES], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%s ", palabras[i]);
    }
    printf("\n");
}

int main() {
    char frase[MAX_CARACTERES];
    char palabras[MAX_CARACTERES / 2][MAX_CARACTERES]; // Suponiendo max. 50 palabras
    int cantidad;

    leerFrase(frase);
    dividirFrase(frase, palabras, &cantidad);

    printf("Frase:"); 
    imprimirFrase(palabras, cantidad);

    int posicion;
    while (1) {
        printf("Ingrese la posicion de la palabra a reemplazar (0 para terminar): ");
        if (scanf("%d", &posicion) != 1) {
            printf("Error al leer posicion.\n");
            return 1;
        }
        while (getchar() != '\n'); // Limpiar buffer de entrada

        if (posicion == 0) {
            break;
        }

        printf("Ingrese la nueva palabra: ");
        char nueva[MAX_CARACTERES];
        fgets(nueva, sizeof(nueva), stdin);
        nueva[strcspn(nueva, "\n")] = 0; // Eliminar salto de línea

        printf("Reemplazando palabra en posicion %d con '%s'\n", posicion, nueva);
        reemplazarPalabra(palabras, cantidad, posicion, nueva);
        imprimirFrase(palabras, cantidad);
    }

    return 0;
}



