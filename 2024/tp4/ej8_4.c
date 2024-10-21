/* Ejercicio 8. 
4. ingresarNombre(char nombre[]); 

// Esta sintaxis es equivalente a la de la opción 3, por lo que sólo cambia la definición
/ de la función */

#include <stdio.h> 

#define LARGO 50

// Definimos la función pasándole una copia de la dirección de memoria del arreglo que 
// se va a imprimir
void ingresarNombre(char nombre[]){ 
     
    printf(">>> ¿Cuál es tu nombre?\n");    
    scanf("%s", nombre);                    
    
}

int main() {
    char nombreAImprimir[LARGO];
    ingresarNombre(nombreAImprimir); 
    printf("Tu nombre es %s", nombreAImprimir);

    return 0;
}
