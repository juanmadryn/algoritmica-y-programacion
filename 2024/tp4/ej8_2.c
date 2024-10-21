/* Ejercicio 8. 
2. char* ingresarNombre(); */

// Esta es la alternativa correcta a la opción 1.

#include <stdio.h> 

#define LARGO 50

// Definimos la función
char* ingresarNombre(){ 
    // Declaro como static el arreglo donde almacenará el nombre para que su dirección
    // de memoria no se pierda cuando finalice la función ('nombre' tiene alcance local). 
    static char nombre[LARGO];  
    
    printf(">>> ¿Cuál es tu nombre?\n");    
    scanf("%s", nombre);                    
    
    return nombre; 
}

int main() {
    // Puedo hacer esto porque la dirección de la variable 'nombre' (local a la función) sigue 
    // siendo válida por la declaré static.
    char* nombreAImprimir = ingresarNombre(); 
    printf("Tu nombre es %s", nombreAImprimir);

    return 0;
}
