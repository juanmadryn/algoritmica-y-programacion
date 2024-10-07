
#include <stdio.h>      

int main() {            /* Estrategia: usaremos un 'for' que recorra desde 'a' ó 'A' hasta  
                        el caracter ingresado, sabiendo que a cada caracter le corresponde un valor
                        numérico en el código ASCII */
    char letra;
    
    printf("\n>>> Ingrese una letra: ");   // Pedimos el ingreso de la letra
    scanf("%c", &letra);                   // Se la asignamos a la variable 'letra'

    /* Para determinar si se ingresó una letra mayúscula o minúscula, haremos una selección previa
    teniendo en cuenta sus valores numéricos en el código ASCII. 
    Mayúsculas: de 65 a 90; minúsculas: de 97 a 122. */ 
    if(letra>=65 && letra<=90){   // Si es mayúscula
        for(int i='A'; i<=letra; i++){  // Notar el uso de los caracteres en los índices
            printf("%c ", i);
        }
    } else if(letra>=97 && letra<=122){   // Si es minúscula
        for(int i='a'; i<=letra; i++){
            printf("%c ", i);
        }
    } else {
        printf("El caracter ingresado es inválido\n"); // Mensaje de salida si no se ingresó una letra
    }
    return 0;

}
