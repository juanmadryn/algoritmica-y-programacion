#include <stdio.h>
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[MAX];
    char direccion[MAX];
    double salario;
    Fecha nacimiento;
} Persona;

void crearFecha(Fecha *fecha){
    printf("Ingrese la fecha de nacimiento en formato dd/mm/yyyy: ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
}

void imprimirFecha(Fecha fecha){
    printf("Fecha de nacimiento: %d/%d/%d\n", fecha.dia, fecha.mes, fecha.anio);
}

int main(){
    Fecha fecha; 

    crearFecha(&fecha);

    imprimirFecha(fecha);

    return 0;
}