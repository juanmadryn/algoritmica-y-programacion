/* Ejercicio 5. Escriba un programa que genere un arreglo de 20 números enteros aleatorios entre 0 y 9,
lo imprima y luego elimine los duplicados, imprimiendo el arreglo resultante al finalizar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 20
#define MAXIMO_VALOR 9

int main()
{
    // Declaramos el arreglo de enteros
    int arregloAleatorios[TAMANIO];
    int arregloNoRepetidos[TAMANIO];

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Bucle 'for' que llena el arreglo de numeros aleatorios entre 0 Y 9.
    int numeroAleatorio;
    for (int i = 0; i < TAMANIO; i++)
    {
        numeroAleatorio = rand() % (MAXIMO_VALOR + 1);
        arregloAleatorios[i] = numeroAleatorio;
    }

    // Lo imprimimos en pantalla
    printf("Arreglo de números enteros aleatorios: \n");
    for (int i = 0; i < TAMANIO; i++)
    {
        printf("%d ", arregloAleatorios[i]);
    }

    /* Para cada valor del arreglo de enteros aleatorios (primer bucle 'for') chequea en el arreglo
    de no repetidos si el valor ya está cargado (bucle 'while). Si no lo está, lo carga en la última
    posición. Esa posición será la cantidad de números no repetidos hallados hasta un momento dado
    (variable cantidadNoRepetidos)-1.
    */
    int cantidadNoRepetidos = 1;
    for (int i = 0; i < TAMANIO; i++)
    {
        int repetido = 0;
        int j = 0;
        while (j <= i && repetido == 0)
        {
            if (arregloAleatorios[i] == arregloNoRepetidos[j])
            {
                repetido = 1;
            }
            j++;
        }
        if (repetido == 0)
        {
            arregloNoRepetidos[cantidadNoRepetidos - 1] = arregloAleatorios[i];
            cantidadNoRepetidos++;
        }
    }

    // Imprime en pantalla sólo los valores insertados (no repetidos)
    printf("\n\nArreglo de enteros no repetidos\n");
    for (int i = 0; i < cantidadNoRepetidos - 1; i++)
    {
        printf("%d ", arregloNoRepetidos[i]);
    }

    return 0;
}