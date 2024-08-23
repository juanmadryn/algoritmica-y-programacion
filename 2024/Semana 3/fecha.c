#include <stdio.h>
#include "fecha.h"

void crearFecha(struct Fecha *fecha){
    printf("Ingrese la fecha de nacimiento en formato dd/mm/yyyy: ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
}

void imprimirFecha(struct Fecha fecha){
    printf("Fecha de nacimiento: %d/%d/%d\n", fecha.dia, fecha.mes, fecha.anio);
}