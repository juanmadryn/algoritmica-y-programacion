/*Escriba un programa que contenga un arreglo de longitud 1000 de cadenas
de texto de hasta 30 caracteres cada una. El programa debe permitir al
usuario ingresar una oración y luego verificar si las palabras de la oración
están presentes en el arreglo (diccionario) o no. Si una palabra no está presente,
 el programa debe indicarla y darle la opción al usuario de agregarla. Al
 terminar de analizar el texto, el programa debe imprimir el estado actual del
 diccionario. El programatermina con la palabra “fin”.*/

#include <stdio.h>
#include <string.h>

// Definimos constantes para el número máximo de cadenas y la longitud máxima de cada cadena
#define MAX_CADENAS 1000
#define MAX_LONGITUD 30

int main()
{
    // Declaración del arreglo de cadenas y la variable para la cantidad de cadenas
    char diccionario[MAX_CADENAS][MAX_LONGITUD];
    int cantidad = 0;

    // Bucle principal para ingresar oraciones hasta que el usuario ingrese "fin"
    int continuar = 1;
    while (continuar)
    {
        // Declaración de la variable para la oración ingresada por el usuario
        char oracion[MAX_LONGITUD * 10];
        printf("Ingrese una oracion (o 'fin' para terminar): ");
        // Leemos la oración completa utilizando fgets
        fgets(oracion, sizeof(oracion), stdin);
        // Eliminamos el salto de línea al final de la oración
        oracion[strcspn(oracion, "\n")] = 0;

        // Verificar si el usuario ingresó "fin" para terminar el programa
        if (strcmp(oracion, "fin") == 0)
        {
            continuar = 0;
        }
        else
        {
            // Dividir la oración en palabras utilizando la función strtok
            char *palabra = strtok(oracion, " ");
            while (palabra != NULL)
            {
                // Copiamos el token actual a una variable auxiliar
                char token[MAX_LONGITUD];
                strcpy(token, palabra);

                // Verificar si la palabra está en el diccionario
                int encontrada = 0;
                for (int i = 0; i < cantidad; i++)
                {
                    if (strcmp(diccionario[i], token) == 0)
                    {
                        encontrada = 1;
                        i = cantidad;
                    }
                }

                // Si la palabra no está en el diccionario, preguntar al usuario si desea agregarla
                if (!encontrada)
                {
                    printf("La palabra '%s' no esta en el diccionario. Desea agregarla? (s/n): ", token);
                    char respuesta;
                    // scanf(" %c", &respuesta);
                    //  Limpiar el buffer de entrada para evitar problemas con caracteres sobrantes
                    respuesta = getchar();
                    getchar();
                    if (respuesta == 's')
                    {
                        // Agregar la palabra al diccionario
                        strcpy(diccionario[cantidad], token);
                        cantidad++;
                    }
                    else
                        printf("\nPalabra no agregada\n");
                }

                // Obtener la siguiente palabra
                palabra = strtok(NULL, " ");
            }
        }

        // Imprimir el estado actual del diccionario
        printf("Estado actual del diccionario:\n");
        for (int i = 0; i < cantidad; i++)
        {
            printf("%s\n", diccionario[i]);
        }
        printf("\n");
    }
    return 0;
}