#include <stdio.h>
#include <string.h>

#define MAX_PALABRAS 10
#define LONGITUD_MAX 21 // 20 caracteres + el terminador nulo

int main()
{
    char lista_palabras[MAX_PALABRAS][LONGITUD_MAX] = {0};
    int cantidad_palabras = 0;
    char nueva_palabra[LONGITUD_MAX] = "";

    do
    {
        // Pedir la entrada del usuario
        printf("Ingrese una palabra (o 'fin' para terminar): ");
        scanf(" %s", nueva_palabra);

        // Verificar si la entrada es "fin"
        if (strcmp(nueva_palabra, "fin") != 0)
        {
            // Encontrar la posición donde insertar la nueva cadena
            int posicion = 0;
            while (posicion < cantidad_palabras && strcmp(lista_palabras[posicion], nueva_palabra) < 0)
            {
                posicion++;
            }

            // Si el arreglo no está lleno o la nueva cadena no debería ir al final, la insertamos
            if (cantidad_palabras < MAX_PALABRAS || posicion < MAX_PALABRAS)
            {
                // Si el arreglo está lleno, desplazar y eliminar la última
                if (cantidad_palabras == MAX_PALABRAS)
                {
                    for (int i = MAX_PALABRAS - 1; i > posicion; i--)
                    {
                        strcpy(lista_palabras[i], lista_palabras[i - 1]);
                    }
                    strcpy(lista_palabras[posicion], nueva_palabra);
                }
                else
                { // Si no está lleno, desplazar e insertar
                    for (int i = cantidad_palabras; i > posicion; i--)
                    {
                        strcpy(lista_palabras[i], lista_palabras[i - 1]);
                    }
                    strcpy(lista_palabras[posicion], nueva_palabra);
                    cantidad_palabras++;
                }

                // Imprimir el arreglo actualizado
                for (int i = 0; i < cantidad_palabras; i++)
                {
                    printf("%s\n", lista_palabras[i]);
                }
                printf("\n");
            }
            else
            {
                printf("La palabra '%s' no fue insertada ya que va al final y el arreglo está lleno.\n", nueva_palabra);
            }
        }
    } while (strcmp(nueva_palabra, "fin") != 0);

    return 0;
}
