#include <stdio.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    // Declaración e inicialización de una estructura a través de un puntero
    struct Persona persona2;
    struct Persona *pPersona2 = &persona2; // Declaramos un puntero a la estructura

    // Inicializamos los miembros a través del puntero
    strcpy(pPersona2->nombre, "Maria");
    pPersona2->edad = 25;

    // Acceso a los miembros de la estructura a través del puntero
    printf("Nombre: %s\n", pPersona2->nombre);
    printf("Edad: %d\n", pPersona2->edad);

    return 0;
}