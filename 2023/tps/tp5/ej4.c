#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    char* file_name = "registro.dat";
    char last_execution[MAX_SIZE];
    
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Esta es la primera vez que se ejecuta el programa.\n");
    } else {
        fgets(last_execution, MAX_SIZE, file);
        printf("El programa se ejecutó por última vez el %s\n", last_execution);
        fclose(file);
    }

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(file, "%02d/%02d/%d a las %02d:%02d:%02d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(file);

    return 0;
}