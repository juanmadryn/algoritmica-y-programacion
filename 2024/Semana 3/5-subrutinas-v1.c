#include <stdio.h>
#include <stdlib.h>

#define FILAS 17
#define ASIENTOS 6

int main() {
    float pesos[FILAS][ASIENTOS] = {0.0};
    int opcion;
    
    do {
        printf("\nMenú:\n");
        printf("1. Ingresar un peso nuevo\n");
        printf("2. Borrar un peso\n");
        printf("3. Mostrar el peso de una fila\n");
        printf("4. Mostrar el peso total de los pasajeros del avión\n");
        printf("5. Terminar el programa\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                int fila;
                char asiento;
                float peso;
                
                printf("Ingresa la fila (1-17): ");
                scanf("%d", &fila);
                if (fila < 1 || fila > FILAS) {
                    printf("Número de fila inválido.\n");
                    return;
                }
                
                printf("Ingresa el asiento (A-F): ");
                scanf(" %c", &asiento);
                if (asiento < 'A' || asiento > 'F') {
                    printf("Letra de asiento inválida.\n");
                    return;
                }
                
                printf("Ingresa el peso: ");
                scanf("%f", &peso);
                
                pesos[fila - 1][asiento - 'A'] = peso;
                printf("Peso ingresado correctamente.\n");
                break;
            case 2:
                int fila;
                char asiento;    
                printf("Ingresa la fila (1-17): ");
                scanf("%d", &fila);
                if (fila < 1 || fila > FILAS) {
                    printf("Número de fila inválido.\n");
                    return;
                }
                
                printf("Ingresa el asiento (A-F): ");
                scanf(" %c", &asiento);
                if (asiento < 'A' || asiento > 'F') {
                    printf("Letra de asiento inválida.\n");
                    return;
                }
                
                pesos[fila - 1][asiento - 'A'] = 0.0;
                printf("Peso borrado correctamente.\n");
                break;
            case 3:
                int fila;
                float pesoTotal = 0.0;
                
                printf("Ingresa la fila (1-17): ");
                scanf("%d", &fila);
                if (fila < 1 || fila > FILAS) {
                    printf("Número de fila inválido.\n");
                    return;
                }
                
                for (int j = 0; j < ASIENTOS; j++) {
                    pesoTotal += pesos[fila - 1][j];
                }
                
                printf("El peso total de la fila %d es: %.2f kg\n", fila, pesoTotal);
                break;
            case 4:
                float pesoTotal = 0.0;
    
                for (int i = 0; i < FILAS; i++) {
                    for (int j = 0; j < ASIENTOS; j++) {
                        pesoTotal += pesos[i][j];
                    }
                }
                
                printf("El peso total de los pasajeros del avión es: %.2f kg\n", pesoTotal);
                break;
            case 5:
                printf("Terminando el programa.\n");
                break;
            default:
                printf("Opción inválida. Inténtalo nuevamente.\n");
        }
    } while(opcion != 5);
    
    return 0;
}
