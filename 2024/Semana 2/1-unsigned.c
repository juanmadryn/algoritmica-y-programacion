#include <stdio.h>

int main(){
    int numero1 = 49237236123;
    printf("Entero desbordado: %d\n", numero1);
    
    printf("==================\n");
    unsigned int numero2 = -49237236123;
    printf("Unsigned como decimal: %d\n", numero2);
    printf("Unsigned como unsigned: %u\n", numero2);

    printf("==================\n");
    unsigned long int numero3 = 49237236123;
    printf("Unsigned long: %ld\n", numero3);

    printf("==================\n");
    short int numero4 = 1234;
    printf("Short como decimal: %d\n", numero4);
    printf("Short como short: %hd\n", numero4);
}