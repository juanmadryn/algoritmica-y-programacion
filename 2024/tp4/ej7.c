/* Ejercicio 7. Escribe un programa que implemente una función que modifique una variable 
tipo int del programa principal, incrementando en una unidad su valor.
void incrementar(int * n); */

#include <stdio.h> 

// Definimos la función
// El parámetro es un puntero que apuntará a la variable
void incrementar(int *n){
    // Le sumamos 1 al valor de la variable apuntada por el argumento
    *n+=1;
}

int main() {
    int x=15;
    
    printf("Valor de x ANTES de incrementar: %d\n", x);

    // Le pasamos a la función la dirección de memoria de la variable que queremos incrementar
    incrementar(&x);

    // Chequeamos
    printf("Valor de x DESPUÉS de incrementar: %d\n", x);

    return 0;
}