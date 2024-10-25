/*
 Indicá qué es lo que hace la siguiente función recursiva:
*/

#include <stdio.h>

int f(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 0;
    } else {
        return f(n - 2);
    }
}

int main() {
    int n;
    printf("Ingrese un nuemro: ");
    scanf("%d", &n);

    int resultado = f(n);
    if(resultado)
        printf("%d es par\n", n);
    else
        printf("%d es impar\n", n);
    return 0;
}
