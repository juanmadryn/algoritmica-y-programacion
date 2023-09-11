#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    char fecha[] = "23/08/2023";
    char resultado[20];
    
    strncpy(resultado, &fecha[6], 4);
    strncat(resultado, &fecha[3], 2);
    strncat(resultado, fecha, 2);

    printf("%s\n", resultado);

    return 0;
}