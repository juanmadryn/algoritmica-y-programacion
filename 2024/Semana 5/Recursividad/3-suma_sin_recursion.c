#include <stdio.h>

int sumar(int numeros[], int cantidad)
{
    int suma = 0;
    for(int i = 0; i < cantidad; i++){
        suma+=numeros[i];
    }
    return suma;
}

int main()
{
    int numeros[] = {3,6,7,9,1};
    printf("%d\n", sumar(numeros, 5));
}
