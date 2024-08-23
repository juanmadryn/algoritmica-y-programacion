#include <stdio.h>

main(){
    int variable_entera = 5;
    printf("1 - Entero en ubicación %p: %d\n", &variable_entera, variable_entera);
    
    int *puntero_a_variable_entera = &variable_entera;
    *puntero_a_variable_entera = 10;
    printf("2 - Entero en ubicación %p: %d\n", puntero_a_variable_entera, *puntero_a_variable_entera);

    printf("3 - Entero en ubicación %p: %d\n", &variable_entera, variable_entera);
}
