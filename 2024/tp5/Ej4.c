/*
Usando recursividad escribí un programa que dado un número entero positivo N imprima
en pantalla una pirámide de altura N “dibujando” cada nivel de la pirámide con los
números de 1 hasta N. Por ejemplo, si el usuario ingresa 5, el programa debe imprimir
lo siguiente:
    1
   2 2
  3 3 3
 4 4 4 4
5 5 5 5 5
*/


#include <stdio.h>

// Función recursiva para imprimir nivel de pirámide
void imprimirNivel(int nivel, int altura) {
    // Imprimir espacios en blanco
    for (int i = 0; i < altura - nivel; i++) {
        printf(" ");
    }
    
    // Imprimir números del nivel
    for (int i = 0; i < nivel; i++) {
        printf("%d ", nivel);
    }
    
    printf("\n");
}

// Función recursiva para imprimir pirámide
void imprimirPiramide(int nivel, int altura) {
    // Caso base: nivel > altura
    if (nivel > altura) {
        return;
    }
    
    // Imprimir nivel actual
    imprimirNivel(nivel, altura);
    
    // Llamar recursivamente para siguiente nivel
    imprimirPiramide(nivel + 1, altura);
}

int main() {
    int altura;
    printf("Ingrese la altura de la piramide: ");
    scanf("%d", &altura);
    
    imprimirPiramide(1, altura);
    
    return 0;
}