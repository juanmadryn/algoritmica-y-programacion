#include <stdio.h>
#include <string.h>

struct Libro {
    char titulo[100];
    char autor[100];
    int paginas;
};

struct Libro libro_mas_paginas(struct Libro arr[], int tam){
    struct Libro libroMasPaginas = arr[0];
    for(int i = 1; i < tam; i++){
        if(libroMasPaginas.paginas < arr[i].paginas)
            libroMasPaginas = arr[i];
    }
    return libroMasPaginas;
}

int main(){
    struct Libro libro, libros[10];

    strcpy(libro.titulo, "Matar a un ruiseñor");
    strcpy(libro.autor, "Harper Lee");
    libro.paginas = 270;

    libros[0] = libro;

    strcpy(libro.titulo, "Don Quijote de la Mancha");
    strcpy(libro.autor, "Miguel de Cervantes");
    libro.paginas = 190;

    libros[1] = libro;

    strcpy(libro.titulo, "Hojas de hierba");
    strcpy(libro.autor, "Walt Whitman");
    libro.paginas = 105;

    libros[2] = libro;

    struct Libro libroMasPaginas = libro_mas_paginas(libros, 3);
    printf("El libro con más páginas es \"%s\" de %s: %d\n", libroMasPaginas.titulo, libroMasPaginas.autor, libroMasPaginas.paginas);    
}