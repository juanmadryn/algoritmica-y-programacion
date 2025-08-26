#include <stdio.h>
#include "1_struct_fecha.h"

void crearFecha(struct Fecha *f) {
    printf("Ingrese día, mes y año: ");
    scanf("%d %d %d", &f->dia, &f->mes, &f->anio);
}

void imprimirFecha(struct Fecha f) {
    printf("Fecha: %02d/%02d/%04d\n", f.dia, f.mes, f.anio);
}
