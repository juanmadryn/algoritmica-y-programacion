#include "1_struct_fecha.h"
#define MAX 100

struct Persona {
    char nombre[MAX];
    char direccion[MAX];
    double salario;
    struct Fecha nacimiento;
};
