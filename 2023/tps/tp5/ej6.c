#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void imprimirRegistro(struct Persona persona, int numero) {
    printf("%d. %s %s, nacido el %02d-%02d-%04d, edad: %d\n", numero, persona.nombre, persona.apellido,
           persona.fechaNacimiento.dia, persona.fechaNacimiento.mes, persona.fechaNacimiento.ano, persona.edad);
}

int main() {
    FILE *archivo;
    struct Persona persona;
    int numeroRegistros = 0;

    archivo = fopen("datosImportados.dat", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    while (fread(&persona, sizeof(struct Persona), 1, archivo)) {
        numeroRegistros++;
        imprimirRegistro(persona, numeroRegistros);
    }

    fclose(archivo);

    int opcion, numero;

    do {
        printf("\nOpciones:\n");
        printf("1. Mostrar un registro por su número de orden.\n");
        printf("2. Eliminar un registro por su número de orden.\n");
        printf("3. Modificar un registro por su número de orden.\n");
        printf("4. Salir.\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el número de orden del registro a mostrar: ");
                scanf("%d", &numero);
                archivo = fopen("datosImportados.dat", "rb");
                if (archivo == NULL) {
                    perror("Error al abrir el archivo");
                    return EXIT_FAILURE;
                }
                fseek(archivo, (numero - 1) * sizeof(struct Persona), SEEK_SET);
                fread(&persona, sizeof(struct Persona), 1, archivo);
                imprimirRegistro(persona, numero);
                fclose(archivo);
                break;

            case 2:
                printf("Ingrese el número de orden del registro a eliminar: ");
                scanf("%d", &numero);
                archivo = fopen("datosImportados.dat", "r+b");
                if (archivo == NULL) {
                    perror("Error al abrir el archivo");
                    return EXIT_FAILURE;
                }
                fseek(archivo, (numero - 1) * sizeof(struct Persona), SEEK_SET);
                struct Persona personaVacia = {0};
                fwrite(&personaVacia, sizeof(struct Persona), 1, archivo);
                fclose(archivo);
                printf("Registro eliminado.\n");
                break;

            case 3:
                printf("Ingrese el número de orden del registro a modificar: ");
                scanf("%d", &numero);
                archivo = fopen("datosImportados.dat", "r+b");
                if (archivo == NULL) {
                    perror("Error al abrir el archivo");
                    return EXIT_FAILURE;
                }
                fseek(archivo, (numero - 1) * sizeof(struct Persona), SEEK_SET);
                fread(&persona, sizeof(struct Persona), 1, archivo);
                printf("Ingrese el nuevo nombre: ");
                scanf("%s", persona.nombre);
                printf("Ingrese el nuevo apellido: ");
                scanf("%s", persona.apellido);
                printf("Ingrese la nueva fecha de nacimiento (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &persona.fechaNacimiento.dia, &persona.fechaNacimiento.mes, &persona.fechaNacimiento.ano);
                printf("Ingrese la nueva edad: ");
                scanf("%d", &persona.edad);
                fseek(archivo, -sizeof(struct Persona), SEEK_CUR);
                fwrite(&persona, sizeof(struct Persona), 1, archivo);
                fclose(archivo);
                printf("Registro modificado.\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 4);

    return 0;
}