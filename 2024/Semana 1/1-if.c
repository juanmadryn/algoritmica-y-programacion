#include <stdio.h>

int main(){
    int edad;

    printf("Por favor, ingrese su edad: ");
    scanf("%d", &edad);
    
    if(edad >= 18) {
        printf("Usted es mayor de edad dado que tiene %d años", edad);
    } else if (edad >= 13){
        printf("Usted es adolescente dado que tiene %d años", edad);
    } else {
        printf("Usted es un niño dado que tiene %d años", edad);
    }
}