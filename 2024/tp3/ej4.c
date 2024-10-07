/* Ejercicio 4. Modificá el programa del ejercicio E13TP1 para implementar dos funciones, 
una para calcular el producto de dos números como sumas sucesivas y otra para calcular 
la potencia entre dos números N y M como productos sucesivos. (PE N=5, M=3)
int producto(int factor1, int factor2);
int potencia(int base, int exponente); */

#include <stdio.h>

int producto(int factor1, int factor2){
    int producto=0;
    for(int i=0; i<factor2; i++){
        producto+=factor1;
    }
return producto;
}

int potencia(int base, int exponente){
    int potencia=1;
    for(int i=0; i<exponente; i++){
        potencia*=base;
    }
return potencia;
}

int main() {
    int N, M;
    printf("Ingrese el primer número entero (N): ");
    scanf("%d", &N);
    printf("Ingrese el segundo número entero (M): ");
    scanf("%d", &M);
    
    printf("El producto N*M es: %d\n", producto(N,M));
    printf("El resultado de N^M es: %d\n", potencia(N,M));

    return 0;
}
    	

