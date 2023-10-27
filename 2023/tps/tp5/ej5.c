#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Fecha {
    int dia;
    int mes;
    int ano;
};

struct Persona {
    char nombre[50];
    char apellido[50];
    struct Fecha fechaNacimiento;
    int edad;
};

int main() {
    FILE *entrada;
    FILE *salida;
    char linea[100];
    struct Persona persona;

    // Abrimos archivo de entrada
    entrada = fopen("datosAImportar.dat", "r");
    if (entrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return EXIT_FAILURE;
    }

    // Abrimos archivo de salida
    salida = fopen("datosImportados.dat", "wb");
    if (salida == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(entrada);
        return EXIT_FAILURE;
    }

    // Leemos línea por línea y escribimos en el archivo nuevo
    while (fgets(linea, sizeof(linea), entrada) != NULL) {
        sscanf(linea, "%[^;];%[^;];%d/%d/%d;%d", persona.nombre, persona.apellido,
               &persona.fechaNacimiento.dia, &persona.fechaNacimiento.mes, &persona.fechaNacimiento.ano, &persona.edad);
        fwrite(&persona, sizeof(struct Persona), 1, salida);
    }

    // Cerramos ambos archivos
    fclose(entrada);
    fclose(salida);

    printf("Los datos han sido importados con éxito en el archivo 'datosImportados.dat'.\n");

    return 0;
}