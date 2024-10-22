/*
 Escribí un programa con una función recursiva que descomponga un número entero
 positivo N dado como producto de números primos.
*/

#include <stdio.h>
#include <stdbool.h>

// Función para verificar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Función recursiva para descomponer en números primos
void descomponerEnPrimos(int num) {
    // Caso base: número primo
    if (esPrimo(num)) {
        printf("%d", num);
        return;
    }
    
    // Encontrar divisor primo
    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && esPrimo(i)) {
            printf("%d * ", i);
            descomponerEnPrimos(num / i);
            return;
        }
    }
}

int main() {
    int num;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &num);
    
    if (num > 0) {
        printf("Descomposicion en numeros primos: ");
        descomponerEnPrimos(num);
        printf("\n");
    } else {
        printf("Error: Numero no positivo.\n");
    }
    
    return 0;
}