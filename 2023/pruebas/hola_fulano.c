#include <stdio.h>

int main()
{
    char nombreApellido[100];

    printf("Ingresa tu nombre y apellido: ");
    scanf("%[^\n]s", nombreApellido);

    printf("Hola %s.\n", nombreApellido);

    return 0;
}