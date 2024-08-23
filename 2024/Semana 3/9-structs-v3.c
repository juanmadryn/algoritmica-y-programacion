#include <stdio.h>
#include "fecha.h"
#define MAX 100

struct Persona {
    char nombre[MAX];
    char direccion[MAX];
    double salario;
    struct Fecha nacimiento;
};

int main(){
    struct Fecha fecha; 

    crearFecha(&fecha);

    imprimirFecha(fecha);

    return 0;
}