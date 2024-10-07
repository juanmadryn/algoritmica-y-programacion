
#include <stdio.h>      

int main() {            /* Estrategia: usar una estructura de selección múltiple que seleccione
                        la operatoración correspondiente en función del operatorando ingresado 
                        como caracter */
    
    int N,M,result;
    char operator;
    
    printf("\n>>> Ingrese un número entero: ");     // Pedimos un número 
    scanf("%d", &N);                                // Se lo asignamos a la variable N
    
    printf("\n>>> Ingrese otro número entero: ");   // Pedimos otro número 
    scanf("%d", &M);                                // Se lo asignamos a la variable M
    
    printf("\nIngrese el operatorador aritmético ( + , - , * , / ): "); // Pedimos el operatorador
    scanf(" %c",&operator);         // Se lo asignamos a la variable 'operator' (notar el espacio antes del %)
    
    switch(operator){           // Usamos switch() para seleccionar la operatoración correspondiente
        case '+':           // Notar el uso de comillas simples
            result = N + M;
            printf("\n>>> El resultado es %d\n", result);
            break;
        case '-':
            result = N - M;
            printf("\n>>> El resultado es %d\n", result);
            break;
        case '*':
            result = N * M;  
            printf("\n>>> El resultado es %d\n", result);
            break;
        case '/':
            result = N / M;    
            printf("\n>>> El resultado es %d\n", result); 
            break;
        default:
            printf("\nOperador no válido");         
    }    
    
    return 0;

}
