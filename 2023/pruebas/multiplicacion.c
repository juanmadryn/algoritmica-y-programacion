#include <stdio.h>

int main()
{
    int n = 3,
        m = 5,
        resultado = 0;

    while (m > 0)
    {
        resultado = resultado + n;
        m = m - 1;
    }
    printf("Resultado: %d", resultado);
    return 0;
}