#include <stdio.h>      

// Para este ejercicio necesitamos conocer la fecha completa
int main() {
    
    int birthYear, birthMonth, birthDate;         // Variables para fecha de nacimiento
    int currentYear, currentMonth, currentDate;   // Variables para fecha actual
    int age;

    printf(">>> ¿Cuál es tu fecha de nacimiento?\n");    
    // Pedimos el ingreso y almacenamos la fecha de nacimiento dato por dato:
    printf(">>> Anio:\t");
    scanf("%d", &birthYear);
    printf("\n>>> Mes (como número):\t");
    scanf("%d", &birthMonth);
    printf("\n>>> Dia:\t");
    scanf("%d", &birthDate);

    printf(">>> ¿Cuál es la fecha actual\n");    
    // Pedimos el ingreso y almacenamos la fecha actual dato por dato:
    printf(">>> Anio:\t");
    scanf("%d", &currentYear);
    printf("\n>>> Mes (como número):\t");
    scanf("%d", &currentMonth);
    printf("\n>>> Dia:\t");
    scanf("%d", &currentDate);
    
    // Comparamos con 'if' el mes de nacimiento con el actual y calculamos la age. Si son iguales, 
    // comparamos el día.  
    if(birthMonth < currentMonth) {        // Ya pasó mi cumpleaños
        age = currentYear - birthYear;       
    } else if(birthMonth > currentMonth) {     // Todavía no pasó mi cumpleaños
        age = currentYear - birthYear - 1;   
    } else {
        if(birthDate <= currentDate) {       // Ya pasó mi cumpleaños o es hoy
            age = currentYear - birthYear;         
        } else {                            // Todavía no pasó mi cumpleaños
            age = currentYear - birthYear - 1;    
        }
    }    
                                             
    printf("\n>>> Tu age es: %d años\n", age);       // Devolvemos la age exacta
    
    return 0;

}
