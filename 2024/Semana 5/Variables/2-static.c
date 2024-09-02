#include <stdio.h>

void incrementar() {
    static int contador = 0; // Se inicializa solo la primera vez
    contador++;
    printf("Contador: %d\n", contador);
}

int main() {
    incrementar(); // Salida: Contador: 1
    incrementar(); // Salida: Contador: 2
    incrementar(); // Salida: Contador: 3
    return 0;
}
