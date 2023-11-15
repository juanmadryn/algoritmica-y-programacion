#include <stdio.h>
int main(){
    int n, m, base, resultado;
    
    printf("Ingrese un número natural: ");
    scanf("%d", &n);

    printf("Ingrese otro número natural: ");
    scanf("%d", &m);

    resultado = base = n;
    for(int i = 1; i < m; i++){
        printf("i: %d, n: %d, base: %d\n", i, n ,base);
        for(int j = 1; j < base; j++){
            printf("j: %d, n: %d, base: %d\n", j, n ,base);
            resultado += n;
        }
        n = resultado;
    }

    printf("%d", resultado);
    return 0;
}