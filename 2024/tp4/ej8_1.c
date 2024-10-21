/* Ejercicio 8. Modificá el programa del ejercicio E2TP1 para que use una función que reciba 
el ingreso por teclado del usuario y devuelva un arreglo de caracteres que represente el nombre. 
Intente Implementar 4 versiones de la función:
1. char[] ingresarNombre();
2. char* ingresarNombre();
3. ingresarNombre(char *nombre);
4. ingresarNombre(char nombre[]);
¿Cuál sintaxis no es correcta? ¿Por qué? ¿Qué diferencias puedes indicar sobre cada implementación? */

/* La sintaxis del caso 1 es INCORRECTA porque está mal definido el tipo de retorno. 
Si queremos que devuelva un arreglo, lo que necesitamos es que devuelva un puntero al
primer elemento del mismo. */
// Probar este código y observar el error que devuelve:

#include <stdio.h> 

#define LARGO 50

// Definimos la función
char[] ingresarNombre(){ 
    char nombre[LARGO];
    
    printf(">>> ¿Cuál es tu nombre?\n");    
    scanf("%s", nombre);                    
    
    return nombre; 
}

int main() {
    char* nombre1 = ingresarNombre();
    printf("Tu nombre es %s", nombre1);

    return 0;
}
