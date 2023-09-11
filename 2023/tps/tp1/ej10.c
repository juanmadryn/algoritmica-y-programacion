#include <stdio.h>
#include <ctype.h>

int main() {
    char letra;
    
    printf("Ingrese una letra: ");
    scanf("%c", &letra);
    
    // Convertir la letra ingresada a minúscula si es mayúscula
    letra = letra;
    
    if (letra < 'a' || letra > 'Z') {
        printf("Por favor, ingrese una letra entre 'a' y 'Z'.\n");
        return 1;
    }
    
    // Imprimir letras desde 'a' hasta la letra ingresada
    for (char letraI = letra >= 'a' && letra <= 'z' ? 'a' : 'A'; letraI <= letra; letraI++) {
        printf("%c ", letraI);
    }
    printf("\n");
    
    return 0;
}