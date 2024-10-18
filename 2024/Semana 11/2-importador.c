#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo_configuracion.h"

typedef struct {
    int fila;
    char asiento;
    float peso;
} Pasajero;

int main() {
    FILE *archivo = fopen(obtenerValorConfiguracion("archivo_datos"), "ab"); // Abre el archivo en modo binario (append)
    if (archivo == NULL) {
        printf("El archivo no existe!\n");
        return 1; // Error al abrir el archivo
    }

    int fila;
    char asiento;
    float peso;

    // Lee de la entrada estándar el formato "fila,asiento,peso"
    while (scanf("%d,%c,%f", &fila, &asiento, &peso) == 3) {
        // Crea un pasajero con los datos leídos
        Pasajero p;
        p.fila = fila;
        p.asiento = asiento;
        p.peso = peso;

        // Escribe la estructura Pasajero en el archivo binario
        fwrite(&p, sizeof(Pasajero), 1, archivo);
        fflush(archivo);
    }

    fclose(archivo); // Cierra el archivo
    return 0; // Finaliza sin mostrar nada por pantalla
}
