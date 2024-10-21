/*Modificá el programa del ejercicio E10TP3 para que permita ingresar una serie de 5 personas
en un arreglo con todos los datos requeridos. Al insertar una persona debe hacerlo en orden
alfabético por apellido. Si dos personas tienen el mismo apellido debe ordenar por el nombre
y si tienen el mismo apellido y nombre debe hacerlo por la fecha de nacimiento. (implementa
una función para comparar ordinalmente las estructuras ‘Persona’)
*/

#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_PERSONAS 5

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[50];
    char apellido[50];
    struct Fecha fechaNacimiento;
    int edad;
};

// Funcion para obtener la fecha actual
struct Fecha obtenerFechaActual() {
    time_t ahora = time(NULL);
    struct tm *fecha_actual = localtime(&ahora);
    struct Fecha fecha;
    fecha.dia = fecha_actual->tm_mday;
    fecha.mes = fecha_actual->tm_mon + 1;
    fecha.anio = fecha_actual->tm_year + 1900;
    return fecha;
}

// Funcion para calcular la edad
int calcularEdad(struct Fecha fechaNacimiento) {
    struct Fecha fechaActual = obtenerFechaActual();
    int edad = fechaActual.anio - fechaNacimiento.anio;
    if (fechaActual.mes < fechaNacimiento.mes || (fechaActual.mes == fechaNacimiento.mes && fechaActual.dia < fechaNacimiento.dia)) {
        edad--;
    }
    return edad;
}

// Funcion para validar la fecha
int validarFecha(int dia, int mes, int anio) {
    if (anio < 1 || anio > 9999) {
        printf("Error: Año invalido.\n");
        return 0;
    }
    if (mes < 1 || mes > 12) {
        printf("Error: Mes invalido.\n");
        return 0;
    }
    if (dia < 1 || dia > 31) {
        printf("Error: Dia invalido.\n");
        return 0;
    }
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Error: Dia invalido para el mes.\n");
        return 0;
    }
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
            if (dia > 29) {
                printf("Error: Dia invalido para el mes.\n");
                return 0;
            }
        } else {
            if (dia > 28) {
                printf("Error: Dia invalido para el mes.\n");
                return 0;
            }
        }
    }
    return 1;
}

// Funcion para comparar personas
int compararPersonas(struct Persona p1, struct Persona p2) {
    if (strcmp(p1.apellido, p2.apellido) < 0) {
        return -1;
    } else if (strcmp(p1.apellido, p2.apellido) > 0) {
        return 1;
    } else {
        if (strcmp(p1.nombre, p2.nombre) < 0) {
            return -1;
        } else if (strcmp(p1.nombre, p2.nombre) > 0) {
            return 1;
        } else {
            if (p1.fechaNacimiento.anio < p2.fechaNacimiento.anio) {
                return -1;
            } else if (p1.fechaNacimiento.anio > p2.fechaNacimiento.anio) {
                return 1;
            } else {
                if (p1.fechaNacimiento.mes < p2.fechaNacimiento.mes) {
                    return -1;
                } else if (p1.fechaNacimiento.mes > p2.fechaNacimiento.mes) {
                    return 1;
                } else {
                    if (p1.fechaNacimiento.dia < p2.fechaNacimiento.dia) {
                        return -1;
                    } else if (p1.fechaNacimiento.dia > p2.fechaNacimiento.dia) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}

// Funcion para insertar persona en orden
void insertarPersona(struct Persona personas[], int *cantidad, struct Persona nueva) {
    int i = *cantidad;
    while (i > 0 && compararPersonas(nueva, personas[i - 1]) < 0) {
        personas[i] = personas[i - 1];
        i--;
    }
    personas[i] = nueva;
    (*cantidad)++;
}

// Funcion para imprimir datos de la persona
void imprimirDatos(struct Persona persona) {
    printf("La persona %s %s nacio el dia %02d-%02d-%04d y tiene %d anos de edad.\n",
           persona.nombre, persona.apellido, persona.fechaNacimiento.dia, persona.fechaNacimiento.mes, persona.fechaNacimiento.anio, persona.edad);
}

// Funcion para ingresar datos de una persona
struct Persona ingresarPersona() {
    struct Persona persona;
    printf("Ingrese nombre: ");
    scanf("%49s", persona.nombre);

    printf("Ingrese apellido: ");
    scanf("%49s", persona.apellido);

    int dia, mes, anio;
    do {
        printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dia, &mes, &anio);
        if (!validarFecha(dia, mes, anio)) {
            printf("Ingrese una fecha valida.\n");
        }
    } while (!validarFecha(dia, mes, anio));

    persona.fechaNacimiento.dia = dia;
    persona.fechaNacimiento.mes = mes;
    persona.fechaNacimiento.anio = anio;

    persona.edad = calcularEdad(persona.fechaNacimiento);
    return persona;
}

int main() {
    struct Persona personas[MAX_PERSONAS];
    int cantidad = 0;

    while (cantidad < MAX_PERSONAS) {
        printf("Ingrese datos de persona %d:\n", cantidad + 1);
        struct Persona nueva = ingresarPersona();
        insertarPersona(personas, &cantidad, nueva);
        printf("\n");

        char respuesta;
        printf("Desea ingresar otra persona? (s/n): ");
        scanf(" %c", &respuesta);
        if (respuesta != 's' && respuesta != 'S') {
            break;
        }
    }

    printf("\nLista de personas:\n");
    for (int i = 0; i < cantidad; i++) {
        imprimirDatos(personas[i]);
    }

    return 0;
}