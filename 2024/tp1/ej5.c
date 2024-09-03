#include <stdio.h>      

int main() {            

    int N, factorial;

    printf("\n>>> Ingrese un numero natural: ");   // Pedimos el ingreso de número
    scanf("%d", &N);                                // Se lo asignamos a la variable N

    // Programamos un loop 'while' que va calculando el factorial paso a paso
    // Variable que irá almacenando el resultado en cada vuelta del loop
    factorial = 1;
    /* Se ejecuta si N>=1. Notar que si N=0, no entra al loop y el
    resultado es 1 (0! = 1) */
    while(N > 0) {
        factorial = N*factorial;    // Resultado parcial en cada paso
        N -= 1;                     // Restamos 1 a N para la próxima vuelta
    }
    
    printf("\n>>> El resultado es: %d\n", factorial);

    return 0;

}
