/* Ejercicio 8. 
3. ingresarNombre(char *nombre); */

#include <stdio.h> 

#define LARGO 50

// Definimos la función pasándole una copia de la dirección de memoria del arreglo que 
// se va a imprimir
void ingresarNombre(char *nombre){ 
     
    printf(">>> ¿Cuál es tu nombre?\n");    
    scanf("%s", nombre);                    
    
}

int main() {
    char nombreAImprimir[LARGO];
    ingresarNombre(nombreAImprimir); 
    printf("Tu nombre es %s", nombreAImprimir);

    return 0;
}
