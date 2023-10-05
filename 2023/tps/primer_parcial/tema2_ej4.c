#include <stdio.h>

union Mixto {
    int entero;
    float flotante;
    char caracter;
};

int main() {
    union Mixto datosEjemplo;

    // Asignamos un entero
    datosEjemplo.entero = 42;
    printf("Entero: %d\n", datosEjemplo.entero);

    // Asignamos un flotante
    datosEjemplo.flotante = 3.14;
    printf("Flotante: %f\n", datosEjemplo.flotante);

    // Asignamos un carácter
    datosEjemplo.caracter = 'A';
    printf("Carácter: %c\n", datosEjemplo.caracter);

    return 0;
}