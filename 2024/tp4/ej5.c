/* Ejercicio 5. Declara un arreglo ‘a’ de 5 enteros y un puntero a entero ‘p’. Asigna la 
dirección de memoria del primer elemento del arreglo al puntero. Luego, utiliza el 
puntero para imprimir todos los elementos del arreglo.*/

#include <stdio.h> 

#define LARGO 5

int main() {
    int a[LARGO] = {1,3,5,7,9};
    int *p;

    // Asignamos a 'p' la dirección de memoria del primer elemento
    p = &a[0];  

    // Accedemos a los valores del arreglo usando el operador '*' y recorriendo las 5
    // direcciones de memoria consecutivas ocupadas por el mismo
    for(int i=0; i<LARGO; i++){
        printf("%d\t", *(p+i)); // También funcionaría usando *(p++)
    }

    return 0;
}