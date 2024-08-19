#include <stdio.h>
#include <stdarg.h>

// Función para calcular el promedio de una cantidad variable de enteros
double calcularPromedio(int numArgs, ...) {
    va_list argumentos; // Define una variable de tipo va_list para acceder a los argumentos variables
    double suma = 0.0;

    // Inicializa la lista de argumentos variables
    va_start(argumentos, numArgs);

    // Recorre todos los argumentos pasados y realiza la suma
    for (int i = 0; i < numArgs; i++) {
        suma += va_arg(argumentos, int); // Extrae el siguiente argumento (de tipo int)
    }

    // Termina el uso de la lista de argumentos variables
    va_end(argumentos);

    // Devuelve el promedio
    return suma / numArgs;
}

int main() {
    // Ejemplo de uso de la función con parámetros variables
    double promedio1 = calcularPromedio(3, 10, 20, 30);
    double promedio2 = calcularPromedio(5, 5, 10, 15, 20, 25);
    
    printf("Promedio 1: %.2f\n", promedio1);
    printf("Promedio 2: %.2f\n", promedio2);
    
    return 0;
}
