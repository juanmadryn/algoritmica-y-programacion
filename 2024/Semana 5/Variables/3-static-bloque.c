#include <stdio.h>

int main() {
    for(int i = 0; i < 3; i++){
        static int contador = 0; // Se inicializa solo la primera vez
        contador++;
        printf("Contador: %d\n", contador);
    }
    return 0;
}
