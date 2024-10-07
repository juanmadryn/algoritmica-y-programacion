/* Llamamos a la librería estándar "stdio" que contiene las funciones que 
    necesitamos: en este caso printf(): imprimir con formato */
#include <stdio.h>

int main() {
    
    // Declaramos la variable de caracter 'nombre', con longitud grande 
    // para asegurarnos que puede almacenar cualquier nombre
    char name[100];
    
    // Pedimos el ingreso del nombre mediante teclado
    printf(">>> ¿Cuál es tu nombre?\n");
    
    // Almacenamos el nombre ingresado en la variable 'nombre', 
    // sólo tomamos los primeros 99 carácteres dejando un lugar para el \0, 
    // e ignoramos el salto de línea
    scanf("%[^\n]99s", name);
    
    // Imprimimos el saludo con el nombre ingresado
    printf("\n>>> ¡Hola %s!\n", name);
    
    return 0;

}
