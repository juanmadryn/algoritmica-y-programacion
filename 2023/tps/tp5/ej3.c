#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char* file_name = "pidfile";
    FILE* file = fopen(file_name, "r");

    // Verificar si el archivo existe
    if (file != NULL) {
        fclose(file);
        printf("El programa ya se encuentra en ejecución.\n");
        return 1;
    }

    // Crear y escribir en el archivo
    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    // Obtener y escribir el PID en el archivo
    pid_t pid = getpid();
    fprintf(file, "%d", pid);
    fclose(file);

    printf("Se ha creado el archivo con el PID del programa.\n");
    printf("Presione cualquier tecla para borrar el archivo y finalizar.\n");
    getchar(); // Esperar a que el usuario ingrese cualquier tecla

    // Eliminar el archivo
    if (remove(file_name) == 0) {
        printf("El archivo se ha eliminado correctamente.\n");
    } else {
        printf("No se pudo eliminar el archivo.\n");
    }

    return 0;
}