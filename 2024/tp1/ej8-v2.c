#include <stdio.h>

int main() {
    // Variables para la fecha de nacimiento y la fecha actual
    int dia_nac, mes_nac, anio_nac;
    int dia_actual, mes_actual, anio_actual;
    int edad;

    // Solicitar la fecha actual al usuario
    printf("Ingrese la fecha actual (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia_actual, &mes_actual, &anio_actual);

    // Solicitar la fecha de nacimiento al usuario
    printf("Ingrese su fecha de nacimiento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia_nac, &mes_nac, &anio_nac);

    // Calcular la edad
    edad = anio_actual - anio_nac;

    // Ajustar si la fecha de nacimiento aún no ha ocurrido este año
    if (mes_nac > mes_actual || (mes_nac == mes_actual && dia_nac > dia_actual)) {
        edad--;
    }

    // Imprimir la edad
    printf("Tu edad exacta es: %d años\n", edad);

    return 0;
}
