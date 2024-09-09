#include <stdio.h>

int main()
{
    char cadena[100];
    char arreglo_enteros[100];
    int longitud, entero;
    char c, opcion;

    printf("Ingrese un numero: ");
    scanf("%d", &entero);
    arreglo_enteros[0] = entero;

    // cargar el arreglo numero por numero
    for (longitud = 1; longitud < 99; longitud++)
    {
        printf("\nDesea ingresar otro numero (s/n): ");
        getchar();
        if ((opcion = getchar()) == 's')
        {
            // getchar();
            printf("\nIngrese un numero: ");
            // getchar();
            scanf("%d", &entero);
            arreglo_enteros[longitud] = entero;
        }
        else
            break;
    }

    int es_capicua = 1;
    for (int i = 0; i < longitud / 2; i++)
    {
        if (arreglo_enteros[i] != arreglo_enteros[longitud - i - 1])
        {
            es_capicua = 0;
            break;
        }
    }

    if (es_capicua)
    {
        printf("\nes un capicua\n");
    }
    else
    {
        printf("\nno es un capicua\n");
    }

    printf("\nIngrese una cadena de caracteres: ");

    // Leer la cadena caracter por caracter
    getchar();
    for (longitud = 0; longitud < 99; longitud++)
    {
        scanf("%c", &c);
        if (c == '\n')
        {
            break;
        }
        cadena[longitud] = c;
    }
    cadena[longitud] = '\0'; // Agregar el caracter nulo al final

    int es_palindromo = 1;
    for (int i = 0; i < longitud / 2; i++)
    {
        if (cadena[i] != cadena[longitud - i - 1])
        {
            es_palindromo = 0;
            break;
        }
    }

    if (es_palindromo)
    {
        printf("%s es un palindromo\n", cadena);
    }
    else
    {
        printf("%s no es un palindromo\n", cadena);
    }

    return 0;
}