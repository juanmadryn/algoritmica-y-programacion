/* Ejercicio 1. Modificá el ejercicio E11TP1 para que utilice una función que determine si un 
número dado es primo (devuelve 1) o no (devuelve 0) (PS) (PE N=10).
int esPrimo(int numero); */

#include <stdio.h>

int esPrimo(int numero) {
    int i=2;
    
    // Recorro divisores desde desde 2 hasta numero/2 y verifico si alguna división es entera 
    // (resto=0). Almaceno en 'i' el mayor valor alcanzado 
    while(i<=numero/2 && numero%i!=0) {
            i++;
    }

    // Si llegué hasta numero/2 ninguna división fue entera, entonces el número es primo, y 
    // viceversa. 
    if(i < numero/2){
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int entero;
    printf("Ingrese un número entero: ");
    scanf("%d", &entero);
    printf("%d", esPrimo(entero));
    }
    	

