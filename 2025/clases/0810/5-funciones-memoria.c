#include <stdio.h>

void nivel3(int z) {
    int local3 = z + 3;
    printf("  [nivel3] z = %d, &z = %p, &local3 = %p\n", z, (void*)&z, (void*)&local3);
}

void nivel2(int y) {
    int local2 = y + 2;
    printf(" [nivel2] y = %d, &y = %p, &local2 = %p\n", y, (void*)&y, (void*)&local2);
    nivel3(local2);
}

void nivel1(int x) {
    int local1 = x + 1;
    printf("[nivel1] x = %d, &x = %p, &local1 = %p\n", x, (void*)&x, (void*)&local1);
    nivel2(local1);
}

int main() {
    int a = 5;
    printf("[main] a = %d, &a = %p\n", a, (void*)&a);
    nivel1(a);
    return 0;
}
