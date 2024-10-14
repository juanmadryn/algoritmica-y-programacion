#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregar(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = crearNodo(valor);

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
    printf("Elemento %d agregado a la lista.\n", valor);
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *temp = *cabeza;

    // Lista vacía
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Busco el nodo a eliminar
    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Elemento %d no encontrado en la lista.\n", valor);
        return;
    }

    // Si el nodo a eliminar es la cabeza
    if (*cabeza == temp) {
        *cabeza = temp->siguiente;
    }

    // Desenlazar el nodo
    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    }
    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp);
    printf("Elemento %d eliminado de la lista.\n", valor);
}

void modificar(struct Nodo *cabeza, int valorAntiguo, int valorNuevo) {
    struct Nodo *temp = cabeza;

    // Buscar el nodo con el valor a modificar
    while (temp != NULL && temp->dato != valorAntiguo) {
        temp = temp->siguiente;
    }

    // Si el valor no está en la lista
    if (temp == NULL) {
        printf("Elemento %d no encontrado en la lista.\n", valorAntiguo);
        return;
    }

    // Modificar el valor
    temp->dato = valorNuevo;
    printf("Elemento %d modificado a %d en la lista.\n", valorAntiguo, valorNuevo);
}

void imprimirListaAdelante(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;

    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("Elementos de la lista (adelante): ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void imprimirListaAtras(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;

    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Ir al último nodo
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    // Imprimir hacia atrás
    printf("Elementos de la lista (atrás): ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

// Función principal
int main() {
    struct Nodo *lista = NULL;
    
    agregar(&lista, 10);
    agregar(&lista, 20);
    agregar(&lista, 30);
    imprimirListaAdelante(lista);
    imprimirListaAtras(lista);

    modificar(lista, 20, 25);
    imprimirListaAdelante(lista);

    eliminar(&lista, 10);
    imprimirListaAdelante(lista);
    imprimirListaAtras(lista);

    eliminar(&lista, 40);
    imprimirListaAdelante(lista);

    return 0;
}
