#include <stdio.h>

enum DiaDeLaSemana {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};

int main() {
    enum DiaDeLaSemana hoy = MIERCOLES;

    printf("Hoy es el día número: %d\n", hoy); // Muestra 2
    return 0;
}
