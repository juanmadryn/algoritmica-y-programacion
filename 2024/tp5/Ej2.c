/*Escribí un programa que calcule la potencia N-ésima de un número entero
positivo M mediante una función recursiva.
*/

#include <stdio.h>

// Función recursiva para calcular potencia
int potencia(int base, int exponente) {
    // Caso base: exponente 0
    if (exponente == 0) {
        return 1;
    }
    
    // Llamar recursivamente
    return base * potencia(base, exponente - 1);
}

int main() {
    int base, exponente;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);
    
    if (exponente < 0) {
        printf("Error: Exponente negativo no permitido.\n");
        return 1;
    }
    
    int resultado = potencia(base, exponente);
    printf("%d elevado a %d = %d\n", base, exponente, resultado);
    return 0;
}
