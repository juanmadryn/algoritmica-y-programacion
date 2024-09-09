/*Escriba un programa que a partir de un arreglo de 10 fechas
(representadas como cadenas de caracteres) hardcoded indique la mayor y la menor.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // Arreglo de 10 fechas (cadenas de caracteres)
    char fechas[10][11] = {
        "2022-01-01",
        "2024-03-25",
        "2021-09-15",
        "2023-07-20",
        "2020-05-10",
        "2022-08-30",
        "2021-02-28",
        "2024-01-15",
        "2023-04-01",
        "2020-12-31"};

    // Inicializar variables para la fecha mayor y menor
    char mayor[11];
    char menor[11];
    strcpy(mayor, fechas[0]);
    strcpy(menor, fechas[0]);

    // Recorrer el arreglo para encontrar la fecha mayor y menor
    for (int i = 1; i < 10; i++)
    {
        if (strcmp(fechas[i], mayor) > 0)
        {
            strcpy(mayor, fechas[i]);
        }
        if (strcmp(fechas[i], menor) < 0)
        {
            strcpy(menor, fechas[i]);
        }
    }

    // Imprimir la fecha mayor y menor
    printf("Fecha mayor: %s\n", mayor);
    printf("Fecha menor: %s\n", menor);

    return 0;
}
