#include <stdio.h>

struct Fecha {
    int dia;
    int mes;
    int ano;
};

int main() {
    struct Fecha fecha;

    // Pedir al usuario que ingrese la fecha
    printf("Ingrese la fecha (dd/mm/aaaa): ");
    while (scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.ano) != 3) {
        printf("Error: Formato incorrecto. Por favor, ingrese dd/mm/aaaa.\n");
        // Limpiar el buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Ingrese la fecha (dd/mm/aaaa): ");
    }

    // Verificar si la fecha es válida
    if (fecha.dia < 1 || fecha.dia > 31 || fecha.mes < 1 || fecha.mes > 12 || fecha.ano < 1) {
        printf("Error: Fecha inválida.\n");
    } else {
        // Imprimir la fecha en formato dd-mm-aaaa
        printf("La fecha es: %02d-%02d-%04d\n", fecha.dia, fecha.mes, fecha.ano);
    }

    return 0;
}