#include <stdio.h>

// Variable global estática 
// con alcance de archivo
static int archivo1_var = 50; 

void mostrar() {
    printf("Variable estática global: %d\n", archivo1_var);
}
