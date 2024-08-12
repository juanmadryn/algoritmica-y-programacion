#include <stdio.h>

void min_max(int arr[], int tam, int *minimo, int *maximo)
{

    *maximo = *minimo = arr[0];

    for (int i = 0; i < tam; i++)
    {

        if (*maximo < arr[i])
        {
            *maximo = arr[i];
        } else
        if (*minimo > arr[i])
        {
            *minimo = arr[i];
        }
    }
}

int main(){
    int arreglo[10] = {4,8,12,3,8,9,0,2,1},
    maximo, minimo;

    min_max(arreglo, 9, &minimo, &maximo);

    printf("Minimo: %d, maximo: %d", minimo, maximo);
    return 0;
}