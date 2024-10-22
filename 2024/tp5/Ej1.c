/*
Escribí un programa que, utilizando una función recursiva, permita saber si una cadena
de caracteres constituye un palíndromo.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función recursiva para verificar palíndromo
bool es_palindromo(char* cadena, int inicio, int fin) {
    // Caso base: si inicio >= fin, es palíndromo
    if (inicio >= fin) {
        return true;
    }

    // Verificar si caracteres en inicio y fin son iguales
    if (cadena[inicio] != cadena[fin]) {
        return false;
    }

    // Llamar recursivamente con inicio+1 y fin-1
    return es_palindromo(cadena, inicio + 1, fin - 1);
}

int main() {
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);

    int longitud = strlen(cadena);
    bool resultado = es_palindromo(cadena, 0, longitud - 1);

    if (resultado) {
        printf("La cadena es un palindromo.\n");
    } else {
        printf("La cadena no es un palindromo.\n");
    }

    return 0;
}
