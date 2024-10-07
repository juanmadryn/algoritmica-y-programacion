/* Ejercicio 3. Escriba un programa que permita realizar la suma de dos vectores de dimensión 5 utilizando
arreglos inicializados en el código (hardcoded) imprimiendo el resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declaro los vectores (arreglos de enteros)
    int vector1[] = {1, 2, 3, 4, 5};
    int vector2[] = {10, 20, 30, 40, 50};
    int suma[5] = {0};

    // La suma de vectores se hace componente a componente. Usamos un bucle 'for'.
    for (int i = 0; i < 5; i++)
    {
        suma[i] = vector1[i] + vector2[i];
    }

    // Imprimimos el vector suma
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", suma[i]);
    }

    return 0;
}