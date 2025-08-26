#include <stdio.h>

void modificarPorValor(int valor) {
    valor = valor + 10;
    printf("[modificarPorValor] dirección de valor = %p, valor = %d\n", (void*)&valor, valor);
}

void modificarPorPunteros(int *puntero) {
    printf("[modificarPorPunteros] dirección del puntero (copiado) = %p, dirección apuntada = %p\n",
           (void*)&puntero, (void*)puntero);
    *puntero = *puntero + 10;
}

int main() {
    int a = 5, b = 5;
    printf("[main] dirección de a = %p, valor = %d\n", (void*)&a, a);
    modificarPorValor(a);
    printf("[main] luego de modificarPorValor, a = %d\n", a);

    printf("\n[main] dirección de b = %p, valor = %d\n", (void*)&b, b);
    modificarPorPunteros(&b);
    printf("[main] luego de modificarPorPunteros, b = %d\n", b);

    return 0;
}
