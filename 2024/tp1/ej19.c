
#include <stdio.h>      
/* Estrategia: eliminar de a una las cifras del número e ir contándolas
hasta que el número sea 0 */
int main() {
    int N,digits,original;
    
    printf("\n>>> Ingrese un número entero: ");   // Pedimos el número 
    scanf("%d", &N);                   // Se lo asignamos a la variable N

    digits=0;       // Inicializamos el contador de dígitos
    original=N;         // Preservamos el originalinal para el mensaje de salida
    while(N>0) {
        N = N/10;       // Le sacamos la última cifra de N
        digits+=1;      // Le sumo 1 al contador
    }    

    printf("\n>>> El número de dígitos de %d es %d\n", original, digits);    
    
    
    return 0;

}
