#include <stdio.h>      
#include <stdbool.h>        // Librería con funciones para variables booleanas.

int main() {            /* Estrategia: dividir N por sus naturales menores hasta 2. Si alguna 
                        división tiene remainder=0, no es primo. Repito para N-1 hasta llegar a 2 */
    int N,n,remainder;
    bool isPrime;

    printf("\n>>> Ingrese un numero natural: ");   // Pedimos el ingreso de número
    scanf("%d", &N);                                // Se lo asignamos a la variable N

    // Programamos un loop 'for' que recorre los naturales desde a N hasta 2.
    // Dentro del 'for' programamos un loop 'while' que va calculando el remainder de las divisiones. 
    // Usaremos la variable booleana 'isPrime' como bandera. Entra al 'while' como 'true', y cambiará a 
    // 'false' si el remainder de alguna división da cero. Imprime el valor si es primo. 
    for(int i=N; i>1; i--) {
        isPrime = true;
        n = i-1;                         // Divisor en cada vuelta del 'while'
        while(isPrime==true && n > 1) {  // Si 'isPrime' cambió a 'false', sale del loop                 
            remainder = i % n;
            if(remainder==0){
                isPrime = false;
            }                           
            n -= 1;                // Restamos 1 a n para la próxima vuelta
        }
        if(isPrime==true) {       // Imprime el valor si es primo y pasa a la siguiente vuelta del 'for'  
            printf("%d\t", i);
        }
    }    
    return 0;

}
