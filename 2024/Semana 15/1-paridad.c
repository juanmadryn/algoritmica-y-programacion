#include <stdio.h>

// Función para calcular el bit de paridad (par) para un conjunto de datos
int calcularBitParidad(int data[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == 1) {
            count++;
        }
    }
    // Si count es par, el bit de paridad es 0; si es impar, el bit de paridad es 1
    return (count % 2 == 0) ? 0 : 1;
}

// Función para verificar si el conjunto de datos cumple con la paridad esperada
int verificarParidad(int data[], int size, int bitParidad) {
    int paridadCalculada = calcularBitParidad(data, size);
    return paridadCalculada == bitParidad;
}

int main() {
    // Ejemplo de datos binarios
    int data[] = {1, 0, 1, 1, 0, 1}; // datos de ejemplo
    int size = sizeof(data) / sizeof(data[0]);

    // Generar el bit de paridad
    int bitParidad = calcularBitParidad(data, size);
    printf("Bit de paridad generado: %d\n", bitParidad);

    // Verificar si los datos cumplen con la paridad
    int datosCorrectos = verificarParidad(data, size, bitParidad);
    if (datosCorrectos) {
        printf("Los datos cumplen con la paridad.\n");
    } else {
        printf("Los datos NO cumplen con la paridad.\n");
    }

    // Modificar un bit de datos para probar la verificación
    data[2] ^= 1; // Cambiamos un bit para simular un error
    datosCorrectos = verificarParidad(data, size, bitParidad);
    if (datosCorrectos) {
        printf("Los datos cumplen con la paridad.\n");
    } else {
        printf("Los datos NO cumplen con la paridad.\n");
    }

    return 0;
}
