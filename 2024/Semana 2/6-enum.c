#include <stdio.h>

enum DiaDeLaSemana {
    LUNES,      // 0
    MARTES,     // 1
    MIERCOLES,  // 2
    JUEVES,     // 3
    VIERNES,    // 4
    SABADO,     // 5
    DOMINGO     // 6
};

int main() {
    enum DiaDeLaSemana hoy;

    hoy = MIERCOLES;

    if (hoy == MIERCOLES) {
        printf("Hoy es miércoles.\n");
    } else {
        printf("Hoy no es miércoles.\n");
    }

    switch (hoy) {
        case LUNES:
            printf("Inicio de la semana.\n");
            break;
        case MARTES:
            printf("Segundo día de la semana.\n");
            break;
        case MIERCOLES:
            printf("Mitad de la semana.\n");
            break;
        case JUEVES:
            printf("Casi fin de semana.\n");
            break;
        case VIERNES:
            printf("Último día laboral para muchos.\n");
            break;
        case SABADO:
            printf("Fin de semana, a descansar.\n");
            break;
        case DOMINGO:
            printf("Día de descanso antes de la semana laboral.\n");
            break;
        default:
            printf("Día no válido.\n");
            break;
    }
    return 0;
}
