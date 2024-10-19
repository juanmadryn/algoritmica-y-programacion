/* Ejercicio 10. Modificá el programa del ejercicio E3TP2 para implementar una función que 
reciba dos arreglos de números enteros de dimensión 5 y devuelvan otro arreglo del mismo tamaño. */

#include <stdio.h> 

// Prototipo de la función
// Los parámetros son los punteros a los primeros elementos de los arreglos a sumar
// y al del arreglo resultado, que definiremos en el main()
void sumarArreglos(int*, int*, int*);

int main(){
    // Declaro los vectores (arreglos de enteros)
    int vector1[] = {1,2,3,4,5};
    int vector2[] = {10,20,30,40,50};
    int resultado[5]={0};

    // Sólo con fines de chequeo de resultados, imprimimos el arreglo 'resultado' antes de
    // ejecutar la función
    for(int i=0; i<5; i++){
        printf("%d\t", resultado[i]);
    }
    
    // Le pasamos a la función las direcciones de memoria del primer elemento de cada arreglo 
    // y el del arreglo resultante
    sumarArreglos(vector1, vector2, resultado);
    
    // Imprimimos el arreglo resultante para chequear
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d\t",resultado[i]);
    }
    
    return 0;
}

// Definición de la función
void sumarArreglos(int arreglo1[], int arreglo2[], int suma[]){
    for(int i=0; i < 5; i++){
        suma[i] = arreglo1[i]+arreglo2[i];
    }    
                    
}

