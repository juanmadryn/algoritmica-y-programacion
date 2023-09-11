#include <stdio.h>

int main()
{
    int n,
        m,
        resultado = 0;

    printf("Ingrese el primer factor de multiplicación: ");
    scanf("%d", &n);

    printf("Ingrese el segundo factor de multiplicación: ");
    scanf("%d", &m);

    while (m-- > 0)
    {
        resultado += n;
    }

    printf("Resultado: %d", resultado);
    return 0;
}