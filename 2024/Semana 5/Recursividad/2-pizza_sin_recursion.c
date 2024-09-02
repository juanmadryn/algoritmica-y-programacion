#include <stdio.h>

int cortarPizza(float circunferencia_porcion)
{
    int porciones = 0;

    while (circunferencia_porcion > 6)
    {
        circunferencia_porcion /= 2.0;
        porciones += 2;
    }

    if (circunferencia_porcion <= 6)
    {
        porciones += 1;
    }

    return porciones;
}

int main()
{
    printf("%d\n", cortarPizza(47));
}
