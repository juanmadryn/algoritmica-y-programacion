#include <stdio.h>

int main() {
    int numeros[5] = {0};
    
    // itero sobre el arreglo
    /*for(int i = 0; i <= 5; i++) {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }*/

    int index = 0;
    while(index < 5){
        printf("Elemento %d: %d\n", index, numeros[index]);
        index++;
    }



    return 0;
}
