#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int fila;
    char asiento;
    float peso;
} Pasajero;

void exportarDesdeArchivo() {
    FILE *archivo = fopen("datos.pasajeros", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo binario.\n");
        return;
    }

    Pasajero p;
    
    // Lee uno a uno los registros del archivo binario
    while (fread(&p, sizeof(Pasajero), 1, archivo) == 1) {
        printf("%d,%c,%.2f\n", p.fila, p.asiento, p.peso);
    }

    fclose(archivo);    
}

int main() {
    exportarDesdeArchivo();
    return 0;
}
