/* Ejercicio 6. Modifica el ejercicio anterior, para presentar en pantalla el valor de ‘p’, y 
las direcciónes de memoria de: ‘a’, ‘a[0]’, ‘a[1]’, ‘a[2]’, ‘a[3]’, ‘a[4]’. 
¿qué conclusión puedes hacer al respecto del resultado?. */

#include <stdio.h> 

#define LARGO 5

int main() {
    int a[LARGO] = {1,3,5,7,9};
    int *p;

    // Asignamos a 'p' la dirección de memoria del primer elemento
    p = &a[0];  

    // Imprimimos el valor de 'p', que es una dirección de memoria (%p)
    printf("Valor de p: %p\n", p);

    // 'a' es un puntero, por  lo que imprimimos su valor igual que lo hecho con 'p' 
    printf("Dirección de memoria de a: %p\n", a);
    
    // Direcciones de memoria de los elementos del arreglo:
    for(int i=0; i<LARGO; i++){
        printf("Dirección de memoria de a[%d]: %p\n", i, &a[i]); // También funcionaría usando *(p++)
    }

    return 0;
}