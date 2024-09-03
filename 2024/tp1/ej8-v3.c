/*Este programa pide al usuario su fecha de nacimiento y la fecha actual, y luego calcula la edad en años, meses y días. Ten en cuenta que este programa asume que todos los meses tienen 30 días, lo que no es exacto. Para una precisión mayor, sería necesario utilizar una biblioteca de fechas y horas.*/

#include <stdio.h>

int main() {
    int birthDate, birthMonth, birthYear;
    int currentDate, currentMonth, currentYear;
    int yearsOfAge, monthsOfAge, daysOfAge;

    // Pedir la fecha de nacimiento
    printf("Ingrese su dia de nacimiento: ");
    scanf("%d", &birthDate);
    printf("Ingrese su mes de nacimiento: ");
    scanf("%d", &birthMonth);
    printf("Ingrese su anio de nacimiento: ");
    scanf("%d", &birthYear);

    // Pedir la fecha actual
    printf("Ingrese el dia actual: ");
    scanf("%d", &currentDate);
    printf("Ingrese el mes actual: ");
    scanf("%d", &currentMonth);
    printf("Ingrese el anio actual: ");
    scanf("%d", &currentYear);

    // Calcular la edad
    yearsOfAge = currentYear - birthYear;
    monthsOfAge = currentMonth - birthMonth;
    daysOfAge = currentDate - birthDate;

    // Ajustar la edad en meses y dias
    if (daysOfAge < 0) {
        daysOfAge += 30; // Asumir mes de 30 dias
        monthsOfAge--;
    }
    if (monthsOfAge < 0) {
        monthsOfAge += 12;
        yearsOfAge--;
    }

    // Imprimir la edad
    printf("Su edad es: %d anios, %d meses y %d dias\n", yearsOfAge, monthsOfAge, daysOfAge);

    return 0;
}
