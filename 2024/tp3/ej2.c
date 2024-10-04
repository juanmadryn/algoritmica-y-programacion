#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// Estructura para representar una fecha
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Función para convertir una cadena de texto en una estructura Fecha
Fecha convertirFecha(char* fecha) {
    Fecha f;
    char* token;

    // Separar el día
    token = strtok(fecha, "-");
    f.dia = atoi(token);

    // Separar el mes
    token = strtok(NULL, "-");
    f.mes = atoi(token);

    // Separar el año
    token = strtok(NULL, "-");
    f.anio = atoi(token);

    return f;
}

// Función para calcular la edad a partir de la fecha de nacimiento
int calcularEdad(char* fechaNacimiento) {
    // Obtener la fecha actual
    time_t tiempoActual = time(NULL);
    struct tm* fechaActual = localtime(&tiempoActual);

    // Convertir la fecha de nacimiento a estructura Fecha
    Fecha fNacimiento = convertirFecha(fechaNacimiento);

    // Calcular la edad
    int edad = fechaActual->tm_year + 1900 - fNacimiento.anio;

    // Ajustar la edad según el mes y día
    if ((fechaActual->tm_mon + 1) < fNacimiento.mes || 
        ((fechaActual->tm_mon + 1) == fNacimiento.mes && fechaActual->tm_mday < fNacimiento.dia)) {
        edad--;
    }

    return edad;
}

int main() {
    char fechaNacimiento[] = "16-02-1985";
    printf("La edad es: %d\n", calcularEdad(fechaNacimiento));
    return 0;
}