#include <stdio.h>

int main(){
    char letra;
    printf("Ingrese una letra del abecedario: ");
    scanf(" %c", &letra);  // El espacio antes de %c hace que se ignoren espacios en blanco y saltos de línea

    while((letra < 'A' || letra > 'Z') && (letra < 'a' || letra > 'z')){
        printf("Ingrese una letra del abecedario: ");
        scanf(" %c", &letra);  // Nuevamente, el espacio antes de %c
        printf("%c\n", letra);
    }
}
