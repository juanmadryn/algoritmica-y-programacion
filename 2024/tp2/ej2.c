/* Ejercicio 2. Escriba un programa que repita la operación del ejercicio anterior 10 veces y lleve
el registro de la
cantidad de veces que se repite cada uno de los números generados aleatoriamente. Al final, debe imprimir
por pantalla la frecuencia de aparición de cada número.
*/

/* ESTA SOLUCIÓN FUNCIONA PERO NO ES RECOMENDABLE USAR TANTAS VARIABLES. SOLUCIONES
EFICIENTES DEBERÍAN USAR UN ARREGLO PARA IR GUARDANDO LAS FRECUENCIAS, Y CONSTANTES PARA EL NÚMERO DE
REPETICIONES Y LOS TAMAÑOS DE LOS ARREGLOS.
UNA VEZ QUE LEAN EL CÓDIGO, IMAGÍNENSE LA CANTIDAD DE VARIABLES QUE HABRÍA QUE DECLARAR SI EL
RANGO DE LOS NÚMEROS ALEATORIOS FUERA MUCHO MAYOR, O LOS INCONVENIENTES PARA CAMBIAR EL TAMAÑO DEL
ARREGLO O EL NÚMERO DE REPETICIONES...
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declaro el arreglo de enteros y los contadores de cada número
    int arregloAleatorios[10];
    int frecuencia0 = 0;
    int frecuencia1 = 0;
    int frecuencia2 = 0;
    int frecuencia3 = 0;
    int frecuencia4 = 0;
    int frecuencia5 = 0;
    int frecuencia6 = 0;
    int frecuencia7 = 0;
    int frecuencia8 = 0;
    int frecuencia9 = 0;
    int frecuencia10 = 0;

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Bucle 'for' que repite todo el código del ejercicio anterior 10 veces

    for (int k = 0; k < 10; k++)
    {

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

        // Recorro el vector resultante y uso switch para incrementar los contadores
        for (i = 0; i < 10; i++)
        {
            switch (arregloAleatorios[i])
            {
            case 0:
                frecuencia0++;
                break;
            case 1:
                frecuencia1++;
                break;
            case 2:
                frecuencia2++;
                break;
            case 3:
                frecuencia3++;
                break;
            case 4:
                frecuencia4++;
                break;
            case 5:
                frecuencia5++;
                break;
            case 6:
                frecuencia6++;
                break;
            case 7:
                frecuencia7++;
                break;
            case 8:
                frecuencia8++;
                break;
            case 9:
                frecuencia9++;
                break;
            default:
                frecuencia10++;
            }
        }

        // El ejercicio no lo pide, pero imprimo primero los arreglos para verificar los resultados
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arregloAleatorios[i]);
        }
        printf("\n");
    }

    // Imprimo en pantalla las frecuencias de cada número
    printf(">>> Frecuencia de aparición de cada número: \n");
    printf("Número 0: %d veces\n", frecuencia0);
    printf("Número 1: %d veces\n", frecuencia1);
    printf("Número 2: %d veces\n", frecuencia2);
    printf("Número 3: %d veces\n", frecuencia3);
    printf("Número 4: %d veces\n", frecuencia4);
    printf("Número 5: %d veces\n", frecuencia5);
    printf("Número 6: %d veces\n", frecuencia6);
    printf("Número 7: %d veces\n", frecuencia7);
    printf("Número 8: %d veces\n", frecuencia8);
    printf("Número 9: %d veces\n", frecuencia9);
    printf("Número 10: %d veces\n", frecuencia10);

    return 0;
}