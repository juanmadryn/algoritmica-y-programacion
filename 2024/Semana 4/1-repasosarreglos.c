#include <stdio.h>

main(){
    int arreglo[10];

    printf("Arreglo: \t\t%p\n", arreglo);
    printf("Primera ubicación: \t%p\n", &arreglo[0]);
    printf("Primer elemento: \t%d\n", arreglo[0]);
}