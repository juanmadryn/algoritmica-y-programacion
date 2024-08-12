#include <stdio.h>
#include <math.h>
#define MAX_OPERACIONES 5

float suma(int a, int b) {
    return a + b;
}

float resta(int a, int b) {
    return a - b;
}

float multiplicacion(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    if (b != 0) {
        return (a*1.0) / (b *1.0);
    } else {
        printf("Error: División por cero.\n");
        return 0;
    }
}

float potencia(int a, int b) {
    return pow((double)a, (double)b);
}

int main() {
    // Declaración de un array de punteros a funciones
    float (*operaciones[MAX_OPERACIONES])(int, int) = {suma, resta, multiplicacion, division, potencia};

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
        float resultado = operaciones[opcion - 1](num1, num2);
        printf("Resultado: %f\n", resultado);
    } else {
        printf("Opción no válida.\n");
    }

    return 0;
}