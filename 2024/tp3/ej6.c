/* Ejercicio 6. Modificá el programa del ejercicio E18TP1 para que llene un arreglo de 10 números 
de hasta 5 cifras generados aleatoriamente, pero que sólo inserte números capicúa. 
Implementá para esto una función que devuelva si un número es capicúa. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


# define TAMANIO 5
# define MAXIMO 99999

// Prototipo de la función
int esCapicua(int);

int main() {
    int arregloCapicuas[TAMANIO]={0};
    
    // Semilla para la generacion de numeros aleatorios
    srand(time(NULL));
    
    // Bucle 'while' que llena el arreglo verificando primero si el numero es capicúa. 
    int numeroAleatorio, i=0;
    while(i<TAMANIO){
        numeroAleatorio = rand() % (MAXIMO+1);
        if(esCapicua(numeroAleatorio)){
            arregloCapicuas[i]=numeroAleatorio;
        i++;    
        }
    }    
    
    for(int j=0; j<TAMANIO;j++){
        printf("%d\t", arregloCapicuas[j]);
    }
    return 0;      
      
    }
    	

// Función que determina si es capicúa (como en el E18TP1)    
int esCapicua(int n){
    int invertido=0;
    int original=n;   
    int R; // Resto de las divisiones          
    while(n>0) {
        R = n%10;       
        invertido=invertido*10 + R; 
        n = n/10;       
    }    

    if(original==invertido){
        return 1;
    } else {
        return 0;    
    }
}
