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
    return fibonacci(n-2) + fibonacci(n-1);
}

int main () {
    int n = 8;
    printf("%d-ésimo término de la sucesión de Fibonacci: %d\n", n, fibonacci(n));
}