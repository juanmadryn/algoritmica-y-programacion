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
