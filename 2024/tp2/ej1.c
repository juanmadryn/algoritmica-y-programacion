#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main()
{ 
    int arreglo[SIZE];
    int numero_aleatorio;
    srand(time(NULL));

    printf("los numeros aleatorios sin repetir son: ");
    for (int i=0 ;i < SIZE; i++)
    {
        numero_aleatorio = rand() % 11;
        int x = 0;
        while ( x <= i)
        {            
            if (numero_aleatorio != arreglo[i])
            {
                arreglo[i]=numero_aleatorio;
                x=x+1;
            }
            else 
            {
                if (numero_aleatorio == arreglo[i])
                {
                    numero_aleatorio = rand() % 11;
                    x = 0;
                }
            }             
        }
    }
    for (int i=0 ;i < SIZE; i++) {
        printf("%d ", arreglo[i]);
    }
    return 0;
}