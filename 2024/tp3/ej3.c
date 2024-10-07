/* Ejercicio 3. Modificá la resolución del ejercicio 2 del TP Nº 1 (E2TP1) para implementar 
una función que reciba un arreglo de caracteres como parámetro (nombre) e imprima por 
pantalla el mensaje “¡Hola nombre!”.
void imprimir(char[] nombre); */

#include <stdio.h>

void imprimir(char nombre[]) {
    printf("¡Hola %s!", nombre);
}

int main() {
    char name[100];
    printf("Ingrese su nombre: ");
    scanf("%s", name);

    imprimir(name);
        
}
