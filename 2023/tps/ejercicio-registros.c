#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definición de la unión para almacenar la calificación
union Calificacion {
    int numerica;
    char alfabetica;
};

// Definición de la estructura para el estudiante
struct Estudiante {
    char nombre[50];
    bool esNumerica; // Campo booleano para indicar si la calificación es numérica
    union Calificacion calif;
};

// Función para inicializar los datos de un estudiante
void inicializarEstudiante(struct Estudiante *estudiante, const char *nombre, bool esNumerica, int califNumerica, char califAlfabetica) {
    strcpy(estudiante->nombre, nombre);
    estudiante->esNumerica = esNumerica;
    if (esNumerica) {
        estudiante->calif.numerica = califNumerica;
    } else {
        estudiante->calif.alfabetica = califAlfabetica;
    }
}

// Función para mostrar la información de un estudiante
void mostrarEstudiante(const struct Estudiante *estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    if (estudiante->esNumerica) {
        printf("Calificación: %d (Numérica)\n", estudiante->calif.numerica);
    } else {
        printf("Calificación: %c (Alfabética)\n", estudiante->calif.alfabetica);
    }
}

int main() {
    struct Estudiante estudiante1;
    inicializarEstudiante(&estudiante1, "Juan", true, 85, ' ');
    
    struct Estudiante estudiante2;
    inicializarEstudiante(&estudiante2, "Maria", false, 0, 'A');
    
    mostrarEstudiante(&estudiante1);
    mostrarEstudiante(&estudiante2);
    
    return 0;
}