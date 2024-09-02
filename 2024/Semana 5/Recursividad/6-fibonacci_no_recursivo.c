#include <stdio.h>

int fibonacci(int n)
{
    printf("Fibonacci de %d\n", n);
    
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int resultado = 0;    
    int fibonacci_1 = 1;
    int fibonacci_2 = 0;
    for (int i = 2; i <= n; i++) {
        resultado = fibonacci_1 + fibonacci_2;  // fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
        fibonacci_2 = fibonacci_1;              // fibonacci(n-2) es ahora fibonacci(n-1)
        fibonacci_1 = resultado;                // fibonacci(n-1) es ahora resultado
    }
    return resultado;
}

int main () {
    int n = 8;
    printf("%d-ésimo término de la sucesión de Fibonacci: %d\n", n, fibonacci(n));
}