#include <stdio.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    // Declaración e inicialización de una estructura
    struct Persona persona1;
    strcpy(persona1.nombre, "Juan");
    persona1.edad = 30;

    // Acceso a los miembros de la estructura
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);

    return 0;
}
