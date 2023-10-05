#include "stdio.h"

int suma_matriz(int arr[][10], int filas, int columnas)
{
    int suma = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma += arr[i][j];
        }
    }
    return suma;
}

int main()
{
    int matriz[][10] = {
        {4, 6, 1, 7, 4},
        {6, 8, 8, 1, 0}
    };
    int suma = suma_matriz(matriz, 2, 5);
    printf("suma: %d\n", suma);
    return 0;
}