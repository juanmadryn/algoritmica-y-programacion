#include <stdio.h>

/* Utilidad: limpiar stdin y pausar hasta Enter */
void esperar_enter(void) {
    int c;
    printf("\nPresione Enter para continuar...");
    /* Consumir hasta fin de línea */
    while ((c = getchar()) != '\n' && c != EOF) {}
}

enum DiaDeLaSemana { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

const char* nombre_dia(enum DiaDeLaSemana d) {
    switch (d) {
        case LUNES: return "LUNES";
        case MARTES: return "MARTES";
        case MIERCOLES: return "MIERCOLES";
        case JUEVES: return "JUEVES";
        case VIERNES: return "VIERNES";
        case SABADO: return "SABADO";
        case DOMINGO: return "DOMINGO";
        default: return "(desconocido)";
    }
}

void ejemplo_enums(void) {
    enum DiaDeLaSemana hoy = MIERCOLES; // 2

    printf("\nEjemplo Enumeraciones (enum)\n");
    printf("Valor por defecto de 'hoy' = %d -> %s\n", hoy, nombre_dia(hoy));

    int valor;
    printf("Ingrese un número de día (0=Lunes .. 6=Domingo): ");
    if (scanf("%d", &valor) == 1 && valor >= 0 && valor <= 6) {
        /* Consumir el salto de línea pendiente */
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        enum DiaDeLaSemana d = (enum DiaDeLaSemana)valor;
        printf("Usted eligió: %s\n", nombre_dia(d));
    } else {
        printf("Entrada inválida.\n");
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
    }

    esperar_enter();
}

int main(){
    ejemplo_enums();
}