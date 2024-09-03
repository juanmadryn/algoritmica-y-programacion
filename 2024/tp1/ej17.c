
#include <stdio.h>      

int main() {            
    
    int N, f, fmenos1=1, fmenos2=1;
    
    printf("\n>>> Ingrese el número de términos: ");   // Pedimos el número de términos
    scanf("%d", &N);                   // Se la asignamos a la variable N

    printf(">>> 1 1 ");                 // Los 2 primeros términos son 1 y 1
    for(int i=3; i<=N; i++){            // Empezamos a sumar los términos de a pares a partir del tercero
        f = fmenos1 + fmenos2;
        fmenos2 = fmenos1;             // Una vez calculado el término i-ésimo, redefinimos los dos 
        fmenos1 = f;                   // anteriores para la próxima vuelta del ciclo
            
        printf("%d ", f);               // Vamos imprimiendo el término resultante en cada vuelta
    }
    
    return 0;

}
