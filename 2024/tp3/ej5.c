/* Ejercicio 5. Modificá el programa del ejercicio E20TP1 para que cada operador aritmético 
esté implementado en una función específica.*/

#include <stdio.h>

// Todas las funciones devuelven enteros, excepto la división
int suma(int termino1, int termino2) {
    return termino1 + termino2;
}

int resta(int termino1, int termino2) {
    return termino1 - termino2;
}

int producto(int factor1, int factor2) {
    return factor1*factor2;
}

float division(int dividendo, int divisor) {
    // Casteamos el resultado a float para que nos devuelva la división exacta
    return (float)dividendo/divisor; 
}

// El programa principal es igual al del E10TP1, excepto que usamos las funciones en el switch
int main() {                
    int N,M,result;
    char oper;
    
    printf("\n>>> Ingrese un número entero: ");     
    scanf("%d", &N);                                
    
    printf("\n>>> Ingrese otro número entero: ");   
    scanf("%d", &M);                                
    
    printf("\nIngrese el operador aritmético ( + , - , * , / ): "); 
    scanf(" %c",&oper);         
    
    switch(oper){          
        case '+':           
            printf("\n>>> El resultado es %d\n", suma(N,M));
            break;
        case '-':
            printf("\n>>> El resultado es %d\n", resta(N,M));
            break;
        case '*':
            printf("\n>>> El resultado es %d\n", producto(N,M));
            break;
        case '/':
            printf("\n>>> El resultado es %.2f\n", division(N,M)); 
            break;
        default:
            printf("\nOperador no válido");         
    }    
    
    return 0;

}
    	

