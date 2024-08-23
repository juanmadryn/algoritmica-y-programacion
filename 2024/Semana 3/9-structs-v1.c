#include <stdio.h>
#define MAX 100

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[MAX];
    char direccion[MAX];
    double salario;
    struct Fecha nacimiento;
};

void crearFecha(struct Fecha *fecha){
    printf("Ingrese la fecha de nacimiento en formato dd/mm/yyyy: ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
}

void imprimirFecha(struct Fecha fecha){
    printf("Fecha de nacimiento: %d/%d/%d\n", fecha.dia, fecha.mes, fecha.anio);
}

int main(){
    struct Fecha fecha; 

    crearFecha(&fecha);

    imprimirFecha(fecha);

    return 0;
}