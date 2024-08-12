#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    char apellido[50];
    float nota_final;
};

float promedio_notas(struct Estudiante arr[], int tam){
    float promedio = 0;
    for(int i = 0; i < tam; i++){
        promedio += arr[i].nota_final;
    }
    return promedio/tam;
}

int main(){
    struct Estudiante estudiante, estudiantes[10];

    strcpy(estudiante.nombre, "Juan");
    strcpy(estudiante.apellido, "De los palotes");
    estudiante.nota_final = 7;

    estudiantes[0] = estudiante;

    strcpy(estudiante.nombre, "José");
    strcpy(estudiante.apellido, "Fulano");
    estudiante.nota_final = 8;

    estudiantes[1] = estudiante;

    strcpy(estudiante.nombre, "Martín");
    strcpy(estudiante.apellido, "Pescador");
    estudiante.nota_final = 10;

    estudiantes[2] = estudiante;

    float promedio = promedio_notas(estudiantes, 3);
    printf("El promedio de notas es: %f\n", promedio);    
}