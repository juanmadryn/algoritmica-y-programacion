#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 256

typedef struct {
    int fila;
    char asiento;
    float peso;
} Pasajero;

char* obtenerValorConfiguracion(const char* clave) {
    FILE *archivo = fopen(".env", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo .env");
        return NULL;
    }

    char linea[MAX_LINEA];
    char *valor = NULL;

    while (fgets(linea, sizeof(linea), archivo) && valor == NULL) {
        // Verifica si la línea contiene la clave buscada
        if (strncmp(linea, clave, strlen(clave)) == 0) {
            // Busca el caracter '=' en la línea
            char *igual = strchr(linea, '=');
            if (igual != NULL) {
                // El valor está después del símbolo '='
                valor = strdup(igual + 1);
                
                // Eliminar salto de línea si lo hay
                valor[strcspn(valor, "\n")] = '\0';
            }
        }
    }

    fclose(archivo);
    return valor;
}

void exportarDesdeArchivo() {
    FILE *archivo = fopen(obtenerValorConfiguracion("archivo_datos"), "rb");
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
