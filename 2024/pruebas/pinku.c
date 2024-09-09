#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int triangular_recursivo(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n + triangular_recursivo(n - 1));
    }
}

int triangular_iterativo(int n)
{
    int nro_t = 0;
    for (int x = 0; x <= n; x++)
    {
        nro_t = nro_t + x;
    }
    return nro_t;
}

void numero_triangular()
{
    char sel = 'a';
    int nro, resultado;

    while (sel != 'S')
    {

        printf("+----------------------------------+\n");
        printf("|     Numeros triangulares         |\n");
        printf("+----------------------------------+\n");
        printf("|A. Algoritmo Iterativo            |\n");
        printf("|B. Algoritmo Recursivo            |\n");
        printf("|S. Salir                          |\n");
        printf("+----------------------------------+\n");

        printf("Opcion = ");
        scanf(" %c", &sel);
        sel = toupper(sel);

        nro = 0;
        while (nro < 1)
        {
            printf("Ingrese un numero entero positivo para calcular su triangular.\n");
            printf("Numero = ");
            scanf("%d", &nro);
        }
        switch (sel)
        {
        case 'A':
            resultado = triangular_iterativo(nro);
            printf("El numero triangular en base a %d es %d\n", nro, resultado);
            break;

        case 'B':
            resultado = triangular_recursivo(nro);
            printf("El numero triangular en base a %d es %d\n", nro, resultado);
            break;

        case 'S':
            printf("Volviendo al menu...");

            break;
        }
    }
}

int main(int argc, char *argv[])
{
    numero_triangular();
    return 0;
}