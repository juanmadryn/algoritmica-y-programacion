#include <stdio.h>      

int main() {        
    
    // Declaramos los anios como variables "integer"
    int birthYear, currentYear;

    // Pedimos el ingreso del anio de nacimiento
    printf(">>> ¿Cuál es tu anio de nacimiento?\n");
    /* Lo almacenamos en 'birthYear'. Para valores numéricos
        debemos anteponer el caracter '&' al nombre
        de la variable. Entenderemos el por qué de esto más adelante */
    scanf("%d", &birthYear);
    
    // Pedimos el ingreso del anio actual
    printf(">>> ¿Cuál es el anio actual?\n");
    // Lo almacenamos en 'currentYear'
    scanf("%d", &currentYear);

    /* Calculamos la edad aproximada y la almacenamos en una
    nueva variable 'edad'. Notar que la estamos definiendo 
    y calculando su valor, todo a la vez */
    int edad = currentYear - birthYear;       
                                             
    // Devolvemos la edad aproximada
    printf("\n>>> Tu edad aproximada es: %d anios\n", edad);       
    
    return 0;

}
