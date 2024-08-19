#include <stdio.h>

void incrementar(int x) {
    x = x + 1;
    printf("Dentro de la función: x = %d\n", x);
}

int main() {
    int a = 5;
    printf("Antes de la función: a = %d\n", a);
    incrementar(a);
    printf("Después de la función: a = %d\n", a);
    return 0;
}
