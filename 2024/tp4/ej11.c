/*
Modificá el programa del ejercicio E8TP2 para que utilice dos funciones. Ambas deben recibir un arreglo de cadenas
de caracteres que representen fechas y deben devolver la menor fecha del arreglo en un caso y la mayor en el otro.
*/

#include <stdio.h>
#include <string.h>

// Función para comparar fechas
int compararFechas(char *fecha1, char *fecha2) {
    int dia1, mes1, anio1;
    int dia2, mes2, anio2;

    sscanf(fecha1, "%d/%d/%d", &dia1, &mes1, &anio1);
    sscanf(fecha2, "%d/%d/%d", &dia2, &mes2, &anio2);

    if (anio1 > anio2) return 1;
    if (anio1 < anio2) return -1;

    if (mes1 > mes2) return 1;
    if (mes1 < mes2) return -1;

    if (dia1 > dia2) return 1;
    if (dia1 < dia2) return -1;

    return 0;
}

// Función para encontrar la menor fecha
char* menorFecha(char fechas[10][11]) {
    char* menor = fechas[0];

    for (int i = 1; i < 10; i++) {
        if (compararFechas(fechas[i], menor) < 0) {
            menor = fechas[i];
        }
    }

    return menor;
}

// Función para encontrar la mayor fecha
char* mayorFecha(char fechas[10][11]) {
    char* mayor = fechas[0];

    for (int i = 1; i < 10; i++) {
        if (compararFechas(fechas[i], mayor) > 0) {
            mayor = fechas[i];
        }
    }

    return mayor;
}

int main() {
    char fechas[10][11] = {
        "10/02/2022",
        "25/01/2023",
        "01/06/2021",
        "15/09/2022",
        "28/02/2021",
        "12/08/2023",
        "20/03/2022",
        "05/11/2021",
        "31/12/2022",
        "18/07/2021"
    };

    printf("Menor fecha: %s\n", menorFecha(fechas));
    printf("Mayor fecha: %s\n", mayorFecha(fechas));

    return 0;
}
