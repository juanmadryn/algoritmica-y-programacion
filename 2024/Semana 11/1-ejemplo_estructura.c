#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo_configuracion.h"

#define FILAS 17
#define ASIENTOS 6
#define TOTAL_PASAJEROS (FILAS * ASIENTOS)


typedef struct
{
    int fila;
    char asiento;
    float peso;
} Pasajero;



int calcularIndice(int fila, char asiento)
{
    return (fila - 1) * ASIENTOS + (asiento - 'A');
}

void ingresarPeso(Pasajero pasajeros[TOTAL_PASAJEROS])
{
    int fila;
    char asiento;
    float peso;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    printf("Ingresa el asiento (A-F): ");
    scanf(" %c", &asiento);
    if (asiento < 'A' || asiento > 'F')
    {
        printf("Letra de asiento inválida.\n");
        return;
    }

    printf("Ingresa el peso: ");
    scanf("%f", &peso);

    int indice = calcularIndice(fila, asiento);
    pasajeros[indice].fila = fila;
    pasajeros[indice].asiento = asiento;
    pasajeros[indice].peso = peso;

    printf("Peso ingresado correctamente.\n");
}

void borrarPeso(Pasajero pasajeros[TOTAL_PASAJEROS])
{
    int fila;
    char asiento;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    printf("Ingresa el asiento (A-F): ");
    scanf(" %c", &asiento);
    if (asiento < 'A' || asiento > 'F')
    {
        printf("Letra de asiento inválida.\n");
        return;
    }

    int indice = calcularIndice(fila, asiento);
    pasajeros[indice].peso = 0.0;

    printf("Peso borrado correctamente.\n");
}

void mostrarPesoFila(Pasajero pasajeros[TOTAL_PASAJEROS])
{
    int fila;
    float pesoTotal = 0.0;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    for (char asiento = 'A'; asiento <= 'F'; asiento++)
    {
        int indice = calcularIndice(fila, asiento);
        pesoTotal += pasajeros[indice].peso;
    }

    printf("El peso total de la fila %d es: %.2f kg\n", fila, pesoTotal);
}

void mostrarPesoTotal(Pasajero pasajeros[TOTAL_PASAJEROS])
{
    float pesoTotal = 0.0;

    for (int i = 0; i < TOTAL_PASAJEROS; i++)
    {
        pesoTotal += pasajeros[i].peso;
    }

    printf("El peso total de los pasajeros del avión es: %.2f kg\n", pesoTotal);
}

void guardarEnArchivo(Pasajero pasajeros[TOTAL_PASAJEROS], const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < TOTAL_PASAJEROS; i++)
    {
        if (pasajeros[i].peso > 0)
        {
            fwrite(&pasajeros[i], sizeof(Pasajero), 1, archivo);
        }
    }

    fclose(archivo);
    printf("Datos guardados en el archivo '%s' correctamente.\n", nombreArchivo);
}

void importarDesdeArchivo(Pasajero pasajeros[TOTAL_PASAJEROS], const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Pasajero pasajero;
    while (fread(&pasajero, sizeof(Pasajero), 1, archivo) == 1)
    {
        int indice = calcularIndice(pasajero.fila, pasajero.asiento);
        pasajeros[indice].fila = pasajero.fila;
        pasajeros[indice].asiento = pasajero.asiento;
        pasajeros[indice].peso = pasajero.peso;
    }

    fclose(archivo);
    printf("Datos importados desde el archivo '%s' correctamente.\n", nombreArchivo);
}

int main()
{
    Pasajero pasajeros[TOTAL_PASAJEROS] = {0};
    int opcion;
    char nombreArchivo[50] = obtenerValorConfiguracion("archivo_datos");
    importarDesdeArchivo(pasajeros, nombreArchivo);

    do
    {
        printf("\nMenú:\n");
        printf("1. Ingresar un peso nuevo\n");
        printf("2. Borrar un peso\n");
        printf("3. Mostrar el peso de una fila\n");
        printf("4. Mostrar el peso total de los pasajeros del avión\n");
        printf("5. Terminar el programa\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarPeso(pasajeros);
            guardarEnArchivo(pasajeros, nombreArchivo);
            break;
        case 2:
            borrarPeso(pasajeros);
            guardarEnArchivo(pasajeros, nombreArchivo);
            break;
        case 3:
            mostrarPesoFila(pasajeros);
            break;
        case 4:
            mostrarPesoTotal(pasajeros);
            break;
        case 5:
            printf("Terminando el programa.\n");
            break;
        default:
            printf("Opción inválida. Inténtalo nuevamente.\n");
        }
    } while (opcion != 7);

    return 0;
}