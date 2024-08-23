#include <stdio.h>

void incrementar(int *x) {
    *x = *x + 1;
    printf("Dentro de incrementar(), dirección de x: %p - Valor de x: %p - Contenido de x: %d\n", &x, x, *x);
}

int main() {
    int a = 5;
    printf("Antes de incrementar(), dirección de a: %p - Contenido de a: %d\n", &a, a);
    incrementar(&a);
    printf("Después de incrementar(), dirección de a: %p - Contenido de a: %d\n", &a, a);
    return 0;
}
