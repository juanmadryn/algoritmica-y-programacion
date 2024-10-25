#include <stdio.h>

// Definimos dos funciones que tengan la misma firma (mismo tipo de retorno y parámetros).
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

// Declaramos una función que reciba un puntero a función como argumento.
void operar(int (*operacion)(int, int), int x, int y) {
    int resultado = operacion(x, y);
    printf("El resultado es: %d\n", resultado);
}

int main() {
    // Definimos un puntero a función que puede apuntar a cualquier función que reciba dos enteros y devuelva un entero.
    int (*ptrOperacion)(int, int);

    // Apuntamos el puntero a la función 'suma' y lo usamos.
    ptrOperacion = &suma;
    operar(ptrOperacion, 10, 5);  // Salida: El resultado es: 15

    // Apuntamos el puntero a la función 'resta' y lo usamos.
    ptrOperacion = &resta;
    operar(ptrOperacion, 10, 5);  // Salida: El resultado es: 5

    return 0;
}
