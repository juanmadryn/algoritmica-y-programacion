#include <stdio.h>

#define FILAS 4
#define COLUMNAS 3

int main(){
    int numeros[FILAS][COLUMNAS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {3, 2, 1}};
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            printf("%d", numeros[i][j]);
        }
        printf("\n");
    }
}