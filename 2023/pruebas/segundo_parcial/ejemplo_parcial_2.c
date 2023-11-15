#include <stdio.h>
int main() {
    FILE *archivo = fopen("archivo.txt", "r");
    char caracter;
    int c = 0;
    if (archivo == NULL) {
        return 1;
    }
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            c++;
        }
    }
    if (caracter != '\n' && c > 0) {
        c++;
    }
    printf("%d\n", c);
    fclose(archivo);
    return 0;
}
