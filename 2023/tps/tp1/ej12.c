#include <stdio.h>

int main(){
    int n = 1, resultado = 0;
    
    printf("Ingrese un número natural: ");
    scanf("%d", &n);

    if (n <= 0) {
        resultado = 0;
    } else if (n == 1) {
        resultado = 1;
    } else {
        int nMenos2 = 0;
        int nMenos1 = 1;
        resultado = 0;
        for (int i = 2; i <= n; i++) {
            resultado = nMenos2 + nMenos1;
            nMenos2 = nMenos1;
            nMenos1 = resultado;
        }
    }

    printf("%d", resultado);
    return 0;
}