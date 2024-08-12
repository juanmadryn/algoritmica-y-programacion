#include <stdio.h>
#define MAX_OPERACIONES 5

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero.\n");
        return 0;
    }
}

int potencia(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero.\n");
        return 0;
    }
}

int main() {
    // Declaración de un array de punteros a funciones
    int (*operaciones[MAX_OPERACIONES])(int, int) = {suma, resta, multiplicacion, division, potencia};

    int opcion, num1, num2;
    
    printf("Ingrese dos números enteros: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Seleccione una operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Potencia\n");
    scanf("%d", &opcion);
    
    if (opcion >= 1 && opcion <= MAX_OPERACIONES) {
        int resultado = operaciones[opcion - 1](num1, num2);
        printf("Resultado: %d\n", resultado);
    } else {
        printf("Opción no válida.\n");
    }

    return 0;
}