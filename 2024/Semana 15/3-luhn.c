#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función que aplica el Algoritmo de Luhn a un número dado
int luhnCheck(const char *num) {
    int length = strlen(num);
    int sum = 0;
    int isSecond = 0; // Determina si estamos en el segundo dígito desde la derecha

    // Iteramos desde el final del número hacia el principio
    for (int i = length - 1; i >= 0; i--) {
        if (!isdigit(num[i])) {
            printf("Error: el número contiene caracteres no numéricos.\n");
            return 0;
        }

        int digit = num[i] - '0';

        // Duplicamos cada segundo dígito
        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9; // Si el resultado es mayor a 9, restamos 9
            }
        }

        // Sumamos el dígito (modificado o no) a la suma total
        sum += digit;
        isSecond = !isSecond; // Alternamos para el próximo dígito
    }

    // Si la suma es múltiplo de 10, el número es válido
    return (sum % 10 == 0);
}

int main() {
    char num[20];

    printf("Ingresa el número a verificar: ");
    scanf("%19s", num);

    if (luhnCheck(num)) {
        printf("El número es válido según el Algoritmo de Luhn.\n");
    } else {
        printf("El número no es válido según el Algoritmo de Luhn.\n");
    }

    return 0;
}
