/*Escriba un programa que a partir de un arreglo inicialmente vacío de 10 cadenas de texto de
longitud máxima 20 permita insertar una cadena nueva indicada por el usuario en orden alfabético.
 Al insertar una nueva cadena el programa debe desplazar las cadenas que ya se encuentren en el
 arreglo para hacerle lugar. Si el arreglo está lleno, se debe quitar la última cadena para hacer
 lugar a la nueva, a menos que la nueva sea la última por orden alfabético, en cuyo caso no se
 debe insertar. Ante cada inserción, el programa debe imprimir el arreglo en su nuevo estado.
 El programa termina al ingresar el usuario la palabra “fin”.*/

#include <stdio.h>
#include <string.h>

#define MAX_CADENAS 10
#define MAX_LONGITUD 20

int main()
{
    char arreglo[MAX_CADENAS][MAX_LONGITUD];
    int cantidad = 0;
    int continuar = 1;

    while (continuar)
    {
        char nueva[MAX_LONGITUD];
        printf("Ingrese una cadena (o 'fin' para terminar): ");
        scanf("%s", nueva);

        if (strcmp(nueva, "fin") == 0)
        {
            continuar = 0;
        }
        else
        {
            int indice;
            for (indice = 0; indice < cantidad && strcmp(arreglo[indice], nueva) < 0; indice++)
                ;

            if (cantidad < MAX_CADENAS || indice < cantidad)
            {
                for (int i = cantidad - 1; i >= indice; i--)
                {
                    strcpy(arreglo[i + 1], arreglo[i]);
                }
                strcpy(arreglo[indice], nueva);

                if (cantidad < MAX_CADENAS)
                {
                    cantidad++;
                }
                else
                {
                    cantidad = MAX_CADENAS;
                }
            }
            printf("Arreglo actual:\n");
            for (int i = 0; i < cantidad; i++)
            {
                printf("%s\n", arreglo[i]);
            }
        }
    }

    return 0;
}