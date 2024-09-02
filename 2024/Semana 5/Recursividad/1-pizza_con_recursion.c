#include <stdio.h>

int cortarPizza(float circunferencia_porcion)
{
    if (circunferencia_porcion <= 6)
    {
        return 1;
    }
    float
        sub_porcion_1 = circunferencia_porcion / 2.0,
        sub_porcion_2 = circunferencia_porcion / 2.0;
    return cortarPizza(sub_porcion_1) + cortarPizza(sub_porcion_2);
}

int main()
{
    printf("%d\n", cortarPizza(47));
}
