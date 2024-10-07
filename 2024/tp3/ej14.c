#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_PUNTOS 100
#define _USE_MATH_DEFINES

// Unión para representar latitud y longitud en sistema sexagesimal
typedef union {
    struct {
        int grados;
        int minutos;
        float segundos;
    } sexagesimal;
    float decimal;
} LatLong;

// Estructura para representar un punto geográfico
struct GeoPoint {
    char nombre[30];
    LatLong latitud;
    LatLong longitud;
    int formato; // 0: decimal, 1: sexagesimal
};

// Función para calcular la distancia entre dos puntos
float calcularDistancia(struct GeoPoint punto1, struct GeoPoint punto2) {
    const float radioTierra = 6371; // en kilómetros
    float lat1 = punto1.latitud.decimal * 3.14159 / 180;
    float lat2 = punto2.latitud.decimal * 3.14159 / 180;
    float deltaLat = (lat2 - lat1);
    float deltaLong = (punto2.longitud.decimal - punto1.longitud.decimal) * 3.14159 / 180;

    float haversinLat = pow(sin(deltaLat / 2), 2);
    float haversinLong = pow(sin(deltaLong / 2), 2);

    float distancia = 2 * radioTierra * asin(sqrt(haversinLat + cos(lat1) * cos(lat2) * haversinLong));
    return distancia;
}

// Función para convertir coordenadas sexagesimales a decimales
void sexagesimalADecimal(LatLong *coord) {
    coord->decimal = coord->sexagesimal.grados + (coord->sexagesimal.minutos / 60.0) + (coord->sexagesimal.segundos / 3600.0);
}

// Función para convertir coordenadas decimales a sexagesimales
void decimalASexagesimal(LatLong *coord) {
    int grados = (int)coord->decimal;
    float resto = (coord->decimal - grados) * 60;
    int minutos = (int)resto;
    float segundos = (resto - minutos) * 60;

    coord->sexagesimal.grados = grados;
    coord->sexagesimal.minutos = minutos;
    coord->sexagesimal.segundos = segundos;
}

// Función para ingresar puntos geográficos
void ingresarPuntos(struct GeoPoint puntos[], int *cantidad) {
    if (*cantidad >= MAX_PUNTOS) {
        printf("Error: Maximo numero de puntos alcanzado.\n");
        return;
    }

    struct GeoPoint punto;
    printf("Ingrese nombre del punto: ");
    scanf(" %s", punto.nombre);

    int formato;
    printf("Ingrese formato (0: decimal, 1: sexagesimal): ");
    scanf("%d", &formato);
    punto.formato = formato;

    if (formato == 0) {
        printf("Ingrese latitud (en formato decimal): ");
        scanf("%f", &punto.latitud.decimal);
        printf("Ingrese longitud (en formato decimal): ");
        scanf("%f", &punto.longitud.decimal);
    } else {
        printf("Ingrese latitud (en formato sexagesimal, grados minutos segundos): ");
        scanf("%d %d %f", &punto.latitud.sexagesimal.grados, &punto.latitud.sexagesimal.minutos, &punto.latitud.sexagesimal.segundos);
        sexagesimalADecimal(&punto.latitud);
        printf("Ingrese longitud (en formato sexagesimal, grados minutos segundos): ");
        scanf("%d %d %f", &punto.longitud.sexagesimal.grados, &punto.longitud.sexagesimal.minutos, &punto.longitud.sexagesimal.segundos);
        sexagesimalADecimal(&punto.longitud);
    }

    puntos[*cantidad] = punto;
    (*cantidad)++;
    printf("Punto ingresado con exito.\n");
}

// Función para imprimir puntos geográficos
void imprimirPuntos(struct GeoPoint puntos[], int cantidad) {
    printf("Puntos geograficos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s - ", puntos[i].nombre);
        if (puntos[i].formato == 0) {
            printf("Latitud: %.6f, Longitud: %.6f\n", puntos[i].latitud.decimal, puntos[i].longitud.decimal);
        } else {
            printf("Latitud: %d° %d' %.2f\", Longitud: %d° %d' %.2f\"\n", 
                   puntos[i].latitud.sexagesimal.grados, puntos[i].latitud.sexagesimal.minutos, puntos[i].latitud.sexagesimal.segundos,
                   puntos[i].longitud.sexagesimal.grados, puntos[i].longitud.sexagesimal.minutos, puntos[i].longitud.sexagesimal.segundos);
        }
    }
}

// Función para buscar punto por nombre
int buscarPunto(struct GeoPoint puntos[], int cantidad, char *nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (strcasecmp(puntos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

// Función para calcular distancia entre dos puntos
void calcularDistanciaEntrePuntos(struct GeoPoint puntos[], int cantidad) {
    char nombre1[30], nombre2[30];
    printf("Ingrese nombre del punto 1: ");
    scanf(" %s", nombre1);
    printf("Ingrese nombre del punto 2: ");
    scanf(" %s", nombre2);

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
