#include "stdio.h"

int maximo_array(int arr[], int tam)
{
    int maximo = arr[0];
    for (int i = 1; i < tam; i++)
    {
        if(arr[i] > maximo){
            maximo = arr[i];
        }
    }
    return maximo;
}

int main()
{
    int arreglo[] = {4, 9, 1, 7, 4, 6, 8, 8, 1, 0},
    maximo = maximo_array(arreglo, 10);
    printf("maximo: %d\n", maximo);
    return 0;
}