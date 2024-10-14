#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int fila;
    char asiento;
    float peso;
} Pasajero;

int main() {
    FILE *archivo = fopen("datos.pasajeros", "ab"); // Abre el archivo en modo binario (append)
    if (archivo == NULL) {
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
