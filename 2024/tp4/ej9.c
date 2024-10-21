/* Ejercicio 9. Modificá el programa del ejercicio E1TP2 para que implemente una función que 
reciba el arreglo de números enteros y un número entero y determine si el número dado está o 
no en el arreglo. */

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define LARGO 10

// Prototipo de la función
int buscarEntero(int*, int);

int main(){
    /* Código del E1TP2 que genera el arreglo
    Lo aconsejable sería crear una función que genere el arreglo. Como el ejercicio no lo 
    pide lo dejamos dentro del main(), como estaba en el E1TP2 */
    
    // Declaramos el arreglo de enteros
    int arregloAleatorios[LARGO];

    // Semilla para la generación de números aleatorios
    srand(time(NULL));
    
    /* Bucle 'while'que va llenando el arreglo. Para cada posición tira un número al azar y chequea 
     si está repetido. No avanza de posición hasta que no la llena con un número no repetido */
    int i=0;
    while(i<LARGO){
        int numeroAleatorio = rand() % (LARGO+1);
        int repetido = 0;   // Bandera
        int j = 0;

        while(j<=i && repetido!=1){
            if(arregloAleatorios[j] == numeroAleatorio){
                repetido = 1;
                break;
            }
            j++;
        }
        
        // Si no estaba repetido llena la posición con el número generado
        if(repetido == 0){
        arregloAleatorios[i] = numeroAleatorio;
        i++;
        }
    }    

    // Código nuevo usando la función pedida en el ejercicio
    // Buscamos un número entero en el arreglo usando nuestra función
    int numeroBuscado;
    printf("\n\n>>> Ingrese un número entero\n");
    scanf("%d", &numeroBuscado);
    
    if(buscarEntero(arregloAleatorios, numeroBuscado)){
        printf("\nEl número %d está en el arreglo", numeroBuscado);
    } else {
        printf("\nEl número %d NO está en el arreglo", numeroBuscado);
    }

    return 0;
}

// Definición de la función
int buscarEntero(int *arreglo, int numero){
    int i=0;
    while(i<LARGO){
        if(arreglo[i]==numero){
            return 1;
        } else {
            i++;
        }
    }    

    return 0;

}

