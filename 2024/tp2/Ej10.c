/*Escriba un programa que mantenga un arreglo de 20 cadenas de caracteres de longitud máxima 30
permitiendo al usuario ingresarlas desde el teclado solo si la cadena ingresada es al menos un
20% diferente a cualquier cadena ya ingresada. Para calcular la similitud entre cadenas, se deben
comparar letra a letra y luego calcular (cantidad de letras iguales) dividido entre (tamaño de
la cadena más larga). Luego de cada ingreso, se debe imprimir el arreglo con las cadenas ingresadas.*/

#include <stdio.h>
#include <string.h>

#define MAX_CADENAS 20
#define MAX_LONGITUD 30

int main()
{
    char arreglo[MAX_CADENAS][MAX_LONGITUD];
    int cantidad = 0;

    // Bucle para ingresar cadenas hasta llenar el arreglo
    while (cantidad < MAX_CADENAS)
    {
        char nueva[MAX_LONGITUD];
        printf("Ingrese una cadena: ");
        scanf("%s", nueva);

        int esDiferente = 1;

        // Verificar similitud con cadenas ya ingresadas
        for (int i = 0; (i < cantidad) && esDiferente; i++)
        {
            int longitud1 = strlen(arreglo[i]);
            int longitud2 = strlen(nueva);
            int maxLongitud;

            // Determinar longitud máxima
            if (longitud1 > longitud2)
            {
                maxLongitud = longitud1;
            }
            else
            {
                maxLongitud = longitud2;
            }

            int cantidadLetrasIguales = 0;

            // Contar letras iguales
            for (int j = 0; j < maxLongitud; j++)
            {
                if (j < longitud1 && j < longitud2 && arreglo[i][j] == nueva[j])
                {
                    cantidadLetrasIguales++;
                }
            }

            // Verificar porcentaje de similitud
            if ((cantidadLetrasIguales * 100) / maxLongitud >= 80)
            {
                esDiferente = 0;
            }
        }

        // Agregar cadena al arreglo si es diferente
        if (esDiferente)
        {
            strcpy(arreglo[cantidad], nueva);
            cantidad++;

            printf("Arreglo actual:\n");
            for (int i = 0; i < cantidad; i++)
            {
                printf("%s\n", arreglo[i]);
            }
        }
        else
        {
            printf("La cadena ingresada es muy similar a una ya existente.\n");
        }
    }

    printf("Arreglo lleno. No se permiten ingresar más cadenas.\n");

    return 0;
}