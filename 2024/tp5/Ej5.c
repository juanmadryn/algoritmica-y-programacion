/*
Escribí un programa que, usando una función recursiva, lea una cadena
de caracteres que contenga paréntesis izquierdos y derechos, e indique
si los mismos están balanceados (es decir, si cada paréntesis izquierdo
tiene su correspondiente paréntesis derecho).
*/

#include <stdio.h>
#include <stdbool.h>

// Función recursiva para verificar balance de paréntesis
bool balancear(char* cadena, int* indice, int contador) {
    // Caso base: fin de la cadena y contador es 0
    if (cadena[*indice] == '\0' && contador == 0) {
        return true;
    }
    
    // Caso base: fin de la cadena y contador != 0
    if (cadena[*indice] == '\0' && contador != 0) {
        return false;
    }
    
    // Avanzar en la cadena
    (*indice)++;
    
    // Paréntesis izquierdo
    if (cadena[*indice - 1] == '(') {
        return balancear(cadena, indice, contador + 1);
    }
    
    // Paréntesis derecho
    if (cadena[*indice - 1] == ')') {
        return balancear(cadena, indice, contador - 1);
    }
    
    // Caracter distinto de paréntesis
    return balancear(cadena, indice, contador);
}

int main() {
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);
    
    int indice = 0;
    bool resultado = balancear(cadena, &indice, 0);
    
    if (resultado) {
        printf("La cadena tiene parentesis balanceados.\n");
    } else {
        printf("La cadena no tiene parentesis balanceados.\n");
    }
    
    return 0;
}