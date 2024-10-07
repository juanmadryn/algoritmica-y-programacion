#include <stdio.h>
#include <math.h> // para función log10
#include <stdlib.h> // para función abs

/*Otra versión utilizando el logaritmo de base 10, que nos da
la cantidad de dígitos - 1, por lo que al resultado le sumamos 1*/
int main() {
    int number;
    
    printf("Ingrese un número: ");
    scanf("%d", &number);

    int digitCount;

    if (number == 0) {
        digitCount = 1;
    } else {
        digitCount = (int)log10(abs(number)) + 1;
    }

    printf("El número %d tiene %d digitos.\n", number, digitCount);

    return 0;
}
