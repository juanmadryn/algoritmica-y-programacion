#include <stdio.h>

int largoPalabra(char palabra[]){
    int largoCadena = 0;
    while(palabra[largoCadena] != '\0')
        largoCadena++;
    return largoCadena;
}

int main () {
    char palabra[] = "Juan Manuel Cortez";

    printf("Largo de '%s': %d\n", palabra, largoPalabra(palabra));
}