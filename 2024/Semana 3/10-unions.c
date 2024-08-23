#include <stdio.h>

typedef enum {
    POR_HORA,
    MENSUAL
} tTipoPago;

typedef union {
    int horas;
    double sueldo_mensual;
} Salario;

typedef struct {
    char nombre[50];
    tTipoPago tipo_pago; // 0 para pago por horas, 1 para sueldo mensual
    Salario salario;
} Empleado;

void imprimirSalario(Empleado emp) {
    if (emp.tipo_pago == POR_HORA) {
        printf("Empleado: %s\n", emp.nombre);
        printf("Pago por horas: %d horas trabajadas\n", emp.salario.horas);
    } else {
        printf("Empleado: %s\n", emp.nombre);
        printf("Sueldo mensual: $%.2f\n", emp.salario.sueldo_mensual);
    }
}

int main() {
    Empleado empleadoPorHora = {
        "Juan Pérez", 
        POR_HORA, 
        .salario.horas = 160
    };
    Empleado empleadoMensual = {
        "María Gómez", 
        MENSUAL, 
        .salario.sueldo_mensual = 2500.00
    };

    imprimirSalario(empleadoPorHora);
    imprimirSalario(empleadoMensual);

    return 0;
}
