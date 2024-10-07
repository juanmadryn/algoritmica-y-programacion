
#include <stdio.h>      

/* Estrategia: obtener un número con los dígitos invertedertidos y
compararlo con el originalinal
Investigando un poco, encontraremos un algoritmo de invertedersión de dígitos que 
consiste en dividir a N por 10, obtener el resto (R) y aplicar la siguiente 
ecuación: inverted=inverted*10+R. 'inverted' se inicializa en 0 y el proceso se repite hasta 
que a N no le quedan dígitos */
int main() {
    
    int N,inverted,original,R;
    
    printf("\n>>> Ingrese un número entero: ");   // Pedimos el número 
    scanf("%d", &N);                   // Se lo asignamos a la variable N

    inverted=0;
    original=N;             // Preservamos el valor originalinal para la comparación y el mensaje de salida
    while(N>0) {
        R = N%10;       // La última cifra del número es el resto de su división por 10
        inverted=inverted*10 + R; // Vamos construyendo el número invertedertido
        N = N/10;       // Le sacamos la última cifra de N
    }    

    if(original==inverted){
        printf("\n>>> El número %d es capicúa\n", original);
    } else {
        printf("\n>>> El número %d NO es capicúa\n", original);    
    }
    
    return 0;

}
