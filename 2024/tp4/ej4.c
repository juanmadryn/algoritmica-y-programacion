/*Ejercicio 4. Declara un puntero a entero y asigna la dirección de memoria de una variable entera 
a ese puntero. Luego, imprime el valor de la variable utilizando el puntero. */

#include <stdio.h> 

int main() {
    int x = 10;
    
    // Declaración de un puntero a entero que apunta a la variable entera 'x'. Es decir,
    // el puntero almacena la dirección de memoria donde está almacenada la variable 'x'
    int *p = &x;         

    // Para imprimir el valor de la variable apuntada por 'p', usamos el operador de indirección '*p'  
    printf("El valor de x es %d\n", *p);
   
    return 0;
}