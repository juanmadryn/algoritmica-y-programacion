#include <stdio.h>
#include <string.h>

int main() {
    char nombre[] = "Juan Manuel";

    for(int i = 0; i < strlen(nombre); i++){
        printf("%p: %x\n", &nombre[i], nombre[i]);
    }
}