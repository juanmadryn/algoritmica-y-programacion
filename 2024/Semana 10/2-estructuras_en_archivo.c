#include <stdio.h>
#include <stdlib.h>

// Definición de las estructuras
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

int main() {
    FILE *archivo;
    struct Persona personas[3] = {
        {"Juan", "Pérez", {15, 6, 1990}, 33},
        {"Ana", "Gómez", {23, 3, 1985}, 39},
        {"Carlos", "Rodríguez", {7, 11, 2000}, 23}
    };
    int numeroRegistro;

    // Abrir el archivo para escribir en modo binario ("wb")
    archivo = fopen("personas.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura\n");
        return 1;
    }

    // Escribir las tres instancias en el archivo
    fwrite(personas, sizeof(struct Persona), 3, archivo);

    // Cerrar el archivo después de escribir
    fclose(archivo);

    // Abrir el archivo para leer en modo binario ("rb")
    archivo = fopen("personas.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura\n");
        return 1;
    }

    // Solicitar al usuario el número de registro a leer (1, 2 o 3)
    printf("¿Qué número de registro deseas imprimir? (1-3): ");
    scanf("%d", &numeroRegistro);

    // Validar la entrada
    if (numeroRegistro < 1 || numeroRegistro > 3) {
        printf("Número de registro inválido.\n");
        fclose(archivo);
        return 1;
    }

    // Mover el puntero de archivo al registro correspondiente
    fseek(archivo, (numeroRegistro - 1) * sizeof(struct Persona), SEEK_SET);

    // Leer el registro seleccionado
    struct Persona personaLeida;
    fread(&personaLeida, sizeof(struct Persona), 1, archivo);

    // Imprimir el contenido del registro seleccionado
    printf("\nPersona %d:\n", numeroRegistro);
    printf("Nombre: %s\n", personaLeida.nombre);
    printf("Apellido: %s\n", personaLeida.apellido);
    printf("Fecha de Nacimiento: %02d/%02d/%d\n", personaLeida.fechaNacimiento.dia, personaLeida.fechaNacimiento.mes, personaLeida.fechaNacimiento.anio);
    printf("Edad: %d\n", personaLeida.edad);

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}
