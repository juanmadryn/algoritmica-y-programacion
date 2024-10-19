/*
Escribí un programa que permita guardar un directorio de personas que tengan nombre, apellido, dni y dirección,
 en donde la dirección sea un GeoPoint. El programa debe permitir ingresar una persona nueva guardándola en
 un arreglo en orden alfabético por apellido y nombre. También debe permitir imprimir el directorio completo.
 Además, debe permitir calcular la distancia entre los domicilios de dos personas indicadas mediante el DNI.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_PERSONAS 100
#define MAX_LONGITUD_NOMBRE 50
#define MAX_LONGITUD_DIRECCION 100
#define PI 3.14159265358979323846
#define RADIO_TIERRA 6371 // en kilómetros

typedef struct {
    double latitud;
    double longitud;
} GeoPoint;

typedef struct {
    char nombre[MAX_LONGITUD_NOMBRE];
    char apellido[MAX_LONGITUD_NOMBRE];
    int dni;
    GeoPoint direccion;
} Persona;

// Función para calcular la distancia entre dos puntos utilizando la fórmula de Haversine
double calcularDistancia(GeoPoint punto1, GeoPoint punto2) {
    double lat1 = punto1.latitud * PI / 180;
    double lon1 = punto1.longitud * PI / 180;
    double lat2 = punto2.latitud * PI / 180;
    double lon2 = punto2.longitud * PI / 180;

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = pow(sin(dLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return RADIO_TIERRA * c;
}

// Función para comparar personas por apellido y nombre
int compararPersonas(Persona p1, Persona p2) {
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
            return 0;
        }
    }
}

// Función para insertar persona en orden
void insertarPersona(Persona personas[], int *cantidad, Persona nueva) {
    int i = *cantidad;
    while (i > 0 && compararPersonas(nueva, personas[i - 1]) < 0) {
        personas[i] = personas[i - 1];
        i--;
    }
    personas[i] = nueva;
    (*cantidad)++;
}

// Función para imprimir datos de la persona
void imprimirDatos(Persona persona) {
    printf("Nombre: %s %s\n", persona.nombre, persona.apellido);
    printf("DNI: %d\n", persona.dni);
    printf("Dirección: Latitud %.2f, Longitud %.2f\n\n", persona.direccion.latitud, persona.direccion.longitud);
}

int main() {
    Persona personas[MAX_PERSONAS];
    int cantidad = 0;

    while (1) {
        printf("1. Ingresar persona\n");
        printf("2. Imprimir directorio\n");
        printf("3. Calcular distancia entre dos personas\n");
        printf("4. Salir\n");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Persona nueva;
                printf("Ingrese nombre: ");
                scanf("%49s", nueva.nombre);
                printf("Ingrese apellido: ");
                scanf("%49s", nueva.apellido);
                printf("Ingrese DNI: ");
                scanf("%d", &nueva.dni);
                printf("Ingrese latitud: ");
                scanf("%lf", &nueva.direccion.latitud);
                printf("Ingrese longitud: ");
                scanf("%lf", &nueva.direccion.longitud);
                insertarPersona(personas, &cantidad, nueva);
                break;
            }
            case 2: {
                for (int i = 0; i < cantidad; i++) {
                    imprimirDatos(personas[i]);
                }
                break;
            }
            case 3: {
                int dni1, dni2;
                printf("Ingrese DNI de la primera persona: ");
                scanf("%d", &dni1);
                printf("Ingrese DNI de la segunda persona: ");
                scanf("%d", &dni2);

                Persona *persona1 = NULL;
                Persona *persona2 = NULL;
                for (int i = 0; i < cantidad; i++) {
                    if (personas[i].dni == dni1) {
                        persona1 = &personas[i];
                    }
                    if (personas[i].dni == dni2) {
                        persona2 = &personas[i];
                    }
                }

                if (persona1 != NULL && persona2 != NULL) {
                    double distancia = calcularDistancia(persona1->direccion, persona2->direccion);
                    printf("La distancia entre las dos personas es de %.2f km\n", distancia);
                } else {
                    printf("No se encontraron las personas con los DNI ingresados\n");
                }
                break;
            }
            case 4:
                return 0;
            default:
                printf("Opción inválida\n");
        }
    }

    return 0;
}