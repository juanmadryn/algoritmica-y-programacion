#include <stdio.h>

int main() {
    int n;
    
    printf("Ingrese un número natural n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("No hay números primos menores o iguales a %d.\n", n);
    } else {
        printf("Números primos menores o iguales a %d:\n", n);
        for (int numero = 2; numero <= n; numero++) {
            int esPrimo = 1;
            
            for (int i = 2; i * i <= numero; i++) {
                if (numero % i == 0) {
                    esPrimo = 0;
                }
            }
            if (esPrimo) {
                printf("%d ", numero);
            }
        }
        printf("\n");
    }

    return 0;
}