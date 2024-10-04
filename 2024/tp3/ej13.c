#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_PUNTOS 100

struct GeoPoint {
    char nombre[30];
    float latitud;
    float longitud;
};

// Funcion para calcular la distancia entre dos puntos
float calcularDistancia(struct GeoPoint punto1, struct GeoPoint punto2) {
    const float radioTierra = 6371; // en kilometros
    float lat1 = punto1.latitud * 3.14159 / 180;
    float lat2 = punto2.latitud * 3.14159 / 180;
    float deltaLat = (lat2 - lat1);
    float deltaLong = (punto2.longitud - punto1.longitud) * 3.14159 / 180;

    float haversinLat = pow(sin(deltaLat / 2), 2);
    float haversinLong = pow(sin(deltaLong / 2), 2);

    float distancia = 2 * radioTierra * asin(sqrt(haversinLat + cos(lat1) * cos(lat2) * haversinLong));
    return distancia;
}

// Funcion para ingresar puntos geograficos
void ingresarPuntos(struct GeoPoint puntos[], int *cantidad) {
    if (*cantidad >= MAX_PUNTOS) {
        printf("Error: Maximo numero de puntos alcanzado.\n");
        return;
    }

    struct GeoPoint punto;
    printf("Ingrese nombre del punto: ");
    scanf(" %[^\n]", punto.nombre);

    printf("Ingrese latitud (en formato decimal): ");
    scanf("%f", &punto.latitud);

    printf("Ingrese longitud (en formato decimal): ");
    scanf("%f", &punto.longitud);

    puntos[*cantidad] = punto;
    (*cantidad)++;
    printf("Punto ingresado con exito.\n");
}

// Funcion para imprimir puntos geograficos
void imprimirPuntos(struct GeoPoint puntos[], int cantidad) {
    printf("Puntos geograficos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s - Latitud: %.6f, Longitud: %.6f\n", puntos[i].nombre, puntos[i].latitud, puntos[i].longitud);
    }
}

// Funcion para buscar punto por nombre
int buscarPunto(struct GeoPoint puntos[], int cantidad, char *nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (strcasecmp(puntos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

// Funcion para calcular distancia entre dos puntos
void calcularDistanciaEntrePuntos(struct GeoPoint puntos[], int cantidad) {
    char nombre1[30], nombre2[30];
    printf("Ingrese nombre del punto 1: ");
    scanf(" %[^\n]", nombre1);
    printf("Ingrese nombre del punto 2: ");
    scanf(" %[^\n]", nombre2);

    int indice1 = buscarPunto(puntos, cantidad, nombre1);
    int indice2 = buscarPunto(puntos, cantidad, nombre2);

    if (indice1 != -1 && indice2 != -1) {
        float distancia = calcularDistancia(puntos[indice1], puntos[indice2]);
        printf("Distancia entre %s y %s: %.2f km\n", nombre1, nombre2, distancia);
    } else {
        printf("Error: Uno o ambos puntos no encontrados.\n");
    }
}

int main() {
    struct GeoPoint puntos[MAX_PUNTOS];
    int cantidad = 0;

    int opcion;
    do {
        printf("1. Ingresar punto geografico\n");
        printf("2. Calcular distancia entre dos puntos\n");
        printf("3. Imprimir puntos geograficos\n");
        printf("4. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarPuntos(puntos, &cantidad);
                break;
            case 2:
                calcularDistanciaEntrePuntos(puntos, cantidad);
                break;
            case 3:
                imprimirPuntos(puntos, cantidad);
                break;
            case 4:
                printf("Adios.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}