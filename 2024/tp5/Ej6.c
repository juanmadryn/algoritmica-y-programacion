/*
Considerando las monedas y billetes de curso legal disponibles en nuestro país,
 escribí un programa que, mediante una función recursiva, calcule la cantidad
 mínima de billetes y monedas necesarias para cubrir una suma dada. Por ejemplo,
 si la suma es $ 3.255 el programa debe indica “1 billete de dos mil, 1 billete
 de mil, 1 billete de 200, 1 billete de 50, 1 moneda de 5”.
*/

#include <stdio.h>

// Función recursiva para calcular billetes
int calcularDenominaciones(int monto, int* denominaciones, int cantidadDenominaciones) {
    // Caso base: monto es 0
    if (monto == 0 || monto < denominaciones[cantidadDenominaciones-1]) {
        return monto;
    }
    
    // Encontrar denominación más grande que no supere el monto
    int indice = 0;
    while (indice < cantidadDenominaciones && monto < denominaciones[indice]) {
        indice++;
    }
    
    // Si no se encontró denominación, imprimir error
    if (indice >= cantidadDenominaciones) {
        //printf("hay resto.\n");
        return monto;
    }
    
    // Imprimir denominación y calcular resto
    printf("1 billete de %d\n", denominaciones[indice]);
    calcularDenominaciones(monto - denominaciones[indice], denominaciones, cantidadDenominaciones);
return 0;
}

// Función recursiva para calcular monedas
void calcularMonedas(int monto, int* monedas, int cantidadMonedas) {
    // Caso base: monto es 0
    if (monto == 0) {
        return;
    }
    
    // Encontrar moneda más grande que no supere el monto
    int indice = 0;
    while (indice < cantidadMonedas && monto < monedas[indice]) {
        indice++;
    }
    
    // Si no se encontró moneda, imprimir error
    if (indice >= cantidadMonedas) {
        printf("Error: No se puede calcular monedas.\n");
        return;
    }
    
    // Imprimir moneda y calcular resto
    printf("1 moneda de %d\n", monedas[indice]);
    calcularMonedas(monto - monedas[indice], monedas, cantidadMonedas);
}

int main() {
    int monto;
    printf("Ingrese el monto: $");
    scanf("%d", &monto);
    
    // Denominaciones de billetes
    int billetes[] = {10000, 2000, 1000, 500, 200, 100, 50, 20, 10};
    int cantidadBilletes = 9;
    
    // Denominaciones de monedas
    int monedas[] = {5, 2, 1};
    int cantidadMonedas = 3;
    
    // Calcular billetes
    printf("Billetes:\n");
    int resto = calcularDenominaciones(monto, billetes, cantidadBilletes);
    
    if (resto > 0) {
        printf("Monedas:\n");
        calcularMonedas(resto, monedas, cantidadMonedas);
    }
    
    return 0;
}