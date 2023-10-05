#include <stdio.h>

// Definición de la estructura Fecha
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

// Función para intercambiar dos fechas
void intercambiar_fechas(struct Fecha arr[], int tam)
{
    struct Fecha fechaMenor = arr[0]; // hardcoded a la primera
    struct Fecha fechaMayor = arr[0]; // hardcoded a la primera
    int fechaMenorIndex = 0;          // hardcoded a la primera
    int fechaMayorIndex = 0;          // hardcoded a la primera

    for (int i = 1; i < tam; i++)
    {
        if (arr[i].anio < fechaMenor.anio ||
            (arr[i].anio == fechaMenor.anio && (arr[i].mes < fechaMenor.mes 
                || arr[i].anio == fechaMenor.anio && arr[i].mes == fechaMenor.mes && arr[i].dia < fechaMenor.dia)))
        {
            fechaMenor = arr[i];
            fechaMenorIndex = i;
        }

        if (arr[i].anio > fechaMayor.anio ||
            (arr[i].anio == fechaMayor.anio && (arr[i].mes > fechaMayor.mes 
            || arr[i].anio == fechaMenor.anio && arr[i].mes == fechaMayor.mes && arr[i].dia > fechaMayor.dia)))
        {
            fechaMayor = arr[i];
            fechaMayorIndex = i;
        }
    }

    // Intercambiar la fecha menor con la primera fecha
    struct Fecha temp = arr[0];
    arr[0] = fechaMenor;
    arr[fechaMenorIndex] = temp;

    // Intercambiar la fecha mayor con la última fecha
    temp = arr[tam - 1];
    arr[tam - 1] = fechaMayor;
    arr[fechaMayorIndex] = temp;
}

int main()
{
    // Arreglo hardcoded de fechas
    struct Fecha fechas[] = {
        {12, 4, 2010},
        {5, 9, 2021},
        {8, 2, 2029},
        {10, 12, 2002}};

    int tam = sizeof(fechas) / sizeof(fechas[0]);

    // Llamar a la función para intercambiar fechas
    intercambiar_fechas(fechas, tam);

    // Imprimir el arreglo modificado
    printf("Fecha menor: %d/%d/%d\n", fechas[0].dia, fechas[0].mes, fechas[0].anio);
    printf("Fecha mayor: %d/%d/%d\n", fechas[tam - 1].dia, fechas[tam - 1].mes, fechas[tam - 1].anio);

    return 0;
}