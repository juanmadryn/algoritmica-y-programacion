#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Antes del intercambio: x = %d, y = %d\n", x, y);
    intercambiar(&x, &y);
    printf("Después del intercambio: x = %d, y = %d\n", x, y);
    return 0;
}
