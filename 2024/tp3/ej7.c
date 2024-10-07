#include <stdio.h>

// Subrutina para imprimir los factores primos de un número
void imprimir_factores_primos(int n) {
    // Iteramos desde 2 (el primer número primo) hasta n
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            // Si n es divisible por i, i es un factor primo
            printf("%d", i);
            n = n / i;

            // Si aún quedan más primos, imprimimos un asterisco
            if (n > 1) {
                printf(" * ");
            }
        }
    }
    printf("\n");
}

// Subrutina para validar la entrada del usuario
int obtener_numero() {
    int numero;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    while (numero <= 1) {
        printf("El numero debe ser mayor que 1.\n");
        printf("Ingrese un número entero positivo: ");
        scanf("%d", &numero);
    }

    return numero;
}

int main() {
    int numero = obtener_numero();
    printf("Los factores primos de %d son: ", numero);
    imprimir_factores_primos(numero);

    return 0;
}
