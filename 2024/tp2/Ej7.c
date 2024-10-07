/*Escriba un programa que dado un arreglo de 10 cadenas de caracteres hardcoded lo imprima al derecho
(comenzando por la cadena de la primera posición) y al revés (comenzando por la última).
*/

#include <stdio.h>

int main()
{
    // Arreglo de 10 cadenas de caracteres
    char arreglo[10][20] = {
        "Luz",
        "Kiosco",
        "Sombra",
        "Fuego",
        "Nube",
        "Rueda",
        "Lago",
        "Viento",
        "Cielo",
        "Ola"};

    // Imprimir al derecho
    printf("Al derecho:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s ", arreglo[i]);
    }

    // Imprimir al revés
    printf("\nAl revés:\n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%s ", arreglo[i]);
    }

    return 0;
}
