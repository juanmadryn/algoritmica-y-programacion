#include <stdio.h>      

/* Para este ejercicio necesitamos conocer sólo el día y mes de nacimiento,
        aunque también se pedirá el año para respetar la consigna */
int main() {
    
    int birthYear, birthMonth, birthDate;            // Variables para fecha de nacimiento
    char *saeson;
    
    printf(">>> Ingresa tu fecha de nacimiento (en formato DD MM AAAA)\n");    
    // Pedimos el ingreso y almacenamos la fecha de nacimiento dato por dato:
    scanf("%d %d %d", &birthDate, &birthMonth, &birthYear);
    
    // Verano: 21/12 al 20/3
    // Otoño: 21/3 al 20/6
    // Invierno: 21/6 al 20/9
    // Primavera: 21/9 al 20/12  
    if(birthMonth >= 1 && birthMonth <= 3) {        
        saeson = "VERANO";       
        if(birthMonth == 3 && birthDate > 20) {
            saeson = "OTOÑO";
        }    
    } else if(birthMonth >= 4 && birthMonth <= 6) {     
        saeson = "OTOÑO";   
        if(birthMonth == 6 && birthDate > 20) {
            saeson = "INVIERNO";
        }    
    } else if(birthMonth >=7 && birthMonth <= 9) {     
        saeson = "INVIERNO"; 
        if(birthMonth == 9 && birthDate > 20) {
            saeson = "PRIMAVERA";
        }    
    } else if(birthMonth >= 10 && birthMonth <= 12) {     
        saeson = "PRIMAVERA"; 
        if(birthMonth == 12 && birthDate > 20) {
            saeson = "VERANO";
        }
    } else {                  
        printf(">>> ERROR. Ingrese un mes válido\n");     
    }          
        
    printf("\n>>> Naciste en %s\n", saeson);       // Devolvemos el valor de 'saeson'
    
    return 0;

}
