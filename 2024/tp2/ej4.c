/* Ejercicio 4. Escriba un programa que llene un arreglo con 50 números enteros aleatorios entre 0 y 10,
y calcule e imprima la moda, la media y la desviación estándar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAMANIO 50
#define MAXIMO 10

int main()
{
    // Declaramos el arreglo de enteros y el que contendrá las frecuencias
    int arregloAleatorios[TAMANIO];
    int frecuencias[MAXIMO + 1] = {0};
    int moda;
    double media, desvioEstandar;

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Bucle 'for' que llena el arreglo de numeros aleatorios y va calculando y guardando sus
    // frecuencias en el índice del arreglo frecuencias[] que se corresponde con su valor.
    int numeroAleatorio;
    for (int i = 0; i < TAMANIO; i++)
    {
        numeroAleatorio = rand() % (MAXIMO + 1);
        arregloAleatorios[i] = numeroAleatorio;
        frecuencias[numeroAleatorio]++;
    }

    // MODA
    // Busco la frecuencia maxima. La moda será su índice en el arreglo
    int frecuenciaMaxima = -1;
    for (int i = 0; i < MAXIMO + 1; i++)
    {
        if (frecuencias[i] >= frecuenciaMaxima)
        {
            frecuenciaMaxima = frecuencias[i];
            moda = i;
        }
    }

    // MEDIA
    /* Calculamos la media como la suma de los valores del arreglo dividida por el número de
    datos (TAMANIO). Usamos un bucle 'for' y un acumulador para calcular la suma */
    int suma = 0;
    for (int i = 0; i < TAMANIO; i++)
    {
        suma += arregloAleatorios[i];
    }
    /* La media es de tipo flotante, por lo que debemos castear a 'float' las variables para que
    haga la división de punto flotante */
    media = (float)suma / (float)TAMANIO;

    // DESVIACION ESTANDAR
    /* Definimos un arreglo que contendrá las diferencias cuadráticas entre cada valor y la media.
    Las calculamos con un bucle 'for. Luego las sumamos en otro 'for' y dividimos por (TAMANIO-1).
    La desviación estándar será la raiz cuadrada de ese resultado */
    double diferenciasCuadraticas[50] = {0};
    for (int i = 0; i < TAMANIO; i++)
    {
        diferenciasCuadraticas[i] = pow((arregloAleatorios[i] - media), 2);
    }

    double sumaCuadrados = 0;
    for (int i = 0; i < TAMANIO; i++)
    {
        sumaCuadrados += diferenciasCuadraticas[i];
    }
    desvioEstandar = sqrt(sumaCuadrados / (double)(TAMANIO - 1));

    // Imprimimos en pantalla los resultados
    printf("La moda es: %d\n\n", moda);
    printf("La media es: %.2f\n\n", media);
    printf("La media es: %.3f\n\n", desvioEstandar);

    // Para ver los datos
    for (int i = 0; i < TAMANIO; i++)
    {
        printf("%d \t", arregloAleatorios[i]);
    }

    return 0;
}