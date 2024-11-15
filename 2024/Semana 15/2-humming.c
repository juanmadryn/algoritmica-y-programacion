#include <stdio.h>

// Función para calcular los bits de paridad y generar el código Hamming (7,4)
void generarCodigoHamming(int datos[4], int hamming[7]) {
    // Colocamos los bits de datos en las posiciones correspondientes
    hamming[2] = datos[0];
    hamming[4] = datos[1];
    hamming[5] = datos[2];
    hamming[6] = datos[3];

    // Calculamos los bits de paridad
    hamming[0] = hamming[2] ^ hamming[4] ^ hamming[6]; // paridad para posiciones 1, 3, 5, 7
    hamming[1] = hamming[2] ^ hamming[5] ^ hamming[6]; // paridad para posiciones 2, 3, 6, 7
    hamming[3] = hamming[4] ^ hamming[5] ^ hamming[6]; // paridad para posiciones 4, 5, 6, 7
}

// Función para verificar y corregir un error en el código Hamming
void verificarYCorregirHamming(int hamming[7]) {
    // Calculamos el síndrome (posible posición del error)
    int p1 = hamming[0] ^ hamming[2] ^ hamming[4] ^ hamming[6];
    int p2 = hamming[1] ^ hamming[2] ^ hamming[5] ^ hamming[6];
    int p3 = hamming[3] ^ hamming[4] ^ hamming[5] ^ hamming[6];

    int posicionError = p1 * 1 + p2 * 2 + p3 * 4;

    if (posicionError == 0) {
        printf("No se detectaron errores en el código Hamming.\n");
    } else {
        printf("Error detectado en la posición %d. Corrigiendo...\n", posicionError);
        hamming[posicionError - 1] ^= 1; // Cambia el bit en la posición del error
    }
}

// Función para decodificar el código Hamming y obtener los bits de datos originales
void decodificarHamming(int hamming[7], int datos[4]) {
    // Extraer los bits de datos de las posiciones correctas
    datos[0] = hamming[2];
    datos[1] = hamming[4];
    datos[2] = hamming[5];
    datos[3] = hamming[6];
}

int main() {
    int datos[4];      // Los 4 bits de datos de entrada
    int hamming[7];    // Código Hamming (7 bits) con bits de paridad

    // Solicitar al usuario que ingrese los bits de datos
    printf("Ingrese 4 bits de datos (0 o 1):\n");
    for (int i = 0; i < 4; i++) {
        printf("Bit %d: ", i + 1);
        scanf("%d", &datos[i]);
    }

    // Generar el código Hamming
    generarCodigoHamming(datos, hamming);

    // Mostrar el código Hamming generado
    printf("Código Hamming generado: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hamming[i]);
    }
    printf("\n");

    // Simular un error en el código Hamming para probar la corrección (opcional)
    //hamming[2] ^= 1; // Cambiamos un bit para simular un error

    // Mostrar el código Hamming después de la corrección
    printf("Código Hamming antes de la corrección: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hamming[i]);
    }
    printf("\n");

    // Decodificar el código Hamming para obtener los datos originales
    int datosDecodificados[4];
    decodificarHamming(hamming, datosDecodificados);

    // Mostrar los datos decodificados
    printf("Datos originales con error decodificados: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", datosDecodificados[i]);
    }
    printf("\n");

    // Verificar y corregir el error
    verificarYCorregirHamming(hamming);

    // Mostrar el código Hamming después de la corrección
    printf("Código Hamming después de la corrección: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hamming[i]);
    }
    printf("\n");

    // Decodificar el código Hamming para obtener los datos originales
    decodificarHamming(hamming, datosDecodificados);

    // Mostrar los datos decodificados
    printf("Datos originales decodificados: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", datosDecodificados[i]);
    }
    printf("\n");

    return 0;
}
