#include <stdio.h>
#include <time.h>

int main() {
    // Obtener la fecha actual
    time_t ahora = time(NULL);
    struct tm *fecha_actual = localtime(&ahora);

    // Imprimir la fecha en formato "Hoy es dd/mm/yyyy"
    printf("Hoy es %02d/%02d/%04d\n",
           fecha_actual->tm_mday,
           fecha_actual->tm_mon + 1,
           fecha_actual->tm_year + 1900);

    return 0;
}