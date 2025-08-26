#include <stdio.h>
#define CANTIDAD_ENTEROS 10

int main(){
    int arregloDeEnteros[CANTIDAD_ENTEROS];
    for(int indice = 0; indice < CANTIDAD_ENTEROS; indice++){
        arregloDeEnteros[indice] = 11;
    }
    for(int indice = 0; indice < CANTIDAD_ENTEROS; indice++){
        printf("%d\n", arregloDeEnteros[indice]);
    }
}