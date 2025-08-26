#include <stdio.h>
#include <string.h>
#include "2_struct_persona.h"

// Función para cargar los datos de una persona
void cargarPersona(struct Persona *persona) {
    printf("Ingrese el nombre: ");
    fgets(persona->nombre, MAX, stdin);
    persona->nombre[strcspn(persona->nombre, "\n")] = '\0';  // Quitar salto de línea

    printf("Ingrese la dirección: ");
    fgets(persona->direccion, MAX, stdin);
    persona->direccion[strcspn(persona->direccion, "\n")] = '\0';

    printf("Ingrese el salario: ");
    scanf("%lf", &persona->salario);

    printf("Ingrese la fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &persona->nacimiento.dia, &persona->nacimiento.mes, &persona->nacimiento.anio);
}

// Función para mostrar los datos de una persona
void mostrarPersona(struct Persona persona) {
    persona.salario = 2000;
    printf("\n--- Datos de la Persona ---\n");
    printf("Nombre: %s\n", persona.nombre);
    printf("Dirección: %s\n", persona.direccion);
    printf("Salario: %.2f\n", persona.salario);
    printf("Fecha de nacimiento: %02d/%02d/%04d\n", persona.nacimiento.dia, persona.nacimiento.mes, persona.nacimiento.anio);
    return;
}

int main() {
    struct Persona persona1;

    cargarPersona(&persona1);

    mostrarPersona(persona1);
    
    imprimirFecha(persona1.nacimiento);

    return 0;
}
