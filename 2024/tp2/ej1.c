/*Ejercicio 1. Escriba un programa que llene un arreglo con 10 números enteros aleatorios no repetidos entre 0
y 10 y lo imprima por pantalla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declaramos el arreglo de enteros
    int arregloAleatorios[10];

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    /* Bucle 'while'que va llenando el arreglo. Para cada posición tira un número al azar y chequea
     si está repetido. No avanza de posición hasta que no la llena con un número no repetido */
    int i = 0;
    while (i < 10)
    {
        int numeroAleatorio = rand() % 11;
        int repetido = 0; // Bandera
        int j = 0;

        while (j <= i && repetido != 1)
        {
            if (arregloAleatorios[j] == numeroAleatorio)
            {
                repetido = 1;
                break;
            }
            j++;
        }

        // Si no estaba repetido llena la posición con el número generado
        if (repetido == 0)
        {
            arregloAleatorios[i] = numeroAleatorio;
            i++;
        }
    }

    // Impresión en pantalla
    printf("Arreglo de números enteros aleatorios no repetidos: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arregloAleatorios[i]);
    }

    return 0;
}