#include <stdio.h>
#include <stdlib.h>
#include "archivo_configuracion.h"

struct Pasajero
{
    int fila;
    char asiento;
    float peso;
};

struct Nodo
{
    struct Pasajero dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Función para crear un nuevo nodo con un pasajero
struct Nodo *crearNodo(struct Pasajero pasajero)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = pasajero;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para agregar un pasajero a la lista
void agregar(struct Nodo **cabeza, struct Pasajero pasajero)
{
    struct Nodo *nuevoNodo = crearNodo(pasajero);

    // La lista está vacía, el nuevo nodo es la cabeza
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
    }
    // la lista NO está vacía, el nuevo nodo va al final
    else
    {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
    printf("Pasajero agregado: Fila %d, Asiento %c, Peso %.2f kg.\n", pasajero.fila, pasajero.asiento, pasajero.peso);
}

// Función para eliminar un pasajero
void eliminar(struct Nodo **cabeza, int fila, char asiento)
{
    struct Nodo *temp = *cabeza;

    if (*cabeza != NULL)
    {
        // Busco el nodo a eliminar
        while (temp != NULL && (temp->dato.fila != fila || temp->dato.asiento != asiento))
        {
            temp = temp->siguiente;
        }

        if (temp != NULL)
        {
            // Si el nodo a eliminar es la cabeza
            if (*cabeza == temp)
            {
                *cabeza = temp->siguiente;
            }

            // Desenlazar el nodo
            if (temp->anterior != NULL)
            {
                temp->anterior->siguiente = temp->siguiente;
            }
            if (temp->siguiente != NULL)
            {
                temp->siguiente->anterior = temp->anterior;
            }

            free(temp);
            printf("Pasajero eliminado: Fila %d, Asiento %c.\n", fila, asiento);
        }
        else
        {
            printf("Pasajero no encontrado: Fila %d, Asiento %c.\n", fila, asiento);
        }
    }
    else
    {
        printf("La lista está vacía.\n");
    }
}

// Función para modificar un pasajero
void modificar(struct Nodo *cabeza, int fila, char asiento, float nuevoPeso)
{
    struct Nodo *temp = cabeza;

    // Buscar el pasajero con la fila y asiento a modificar
    while (temp != NULL && (temp->dato.fila != fila || temp->dato.asiento != asiento))
    {
        temp = temp->siguiente;
    }

    if (temp != NULL)
    {
        // Modificar el peso
        temp->dato.peso = nuevoPeso;
        printf("Pasajero modificado: Fila %d, Asiento %c, Nuevo peso %.2f kg.\n", fila, asiento, nuevoPeso);
    }
    // Si el pasajero no está en la lista
    else
    {
        printf("Pasajero no encontrado: Fila %d, Asiento %c.\n", fila, asiento);
    }
}

// Función para imprimir la lista hacia adelante
void imprimirListaAdelante(struct Nodo *cabeza)
{
    struct Nodo *temp = cabeza;

    if (cabeza != NULL)
    {
        printf("Lista de pasajeros (adelante):\n");
        while (temp != NULL)
        {
            printf("Fila %d, Asiento %c, Peso %.2f kg -> ", temp->dato.fila, temp->dato.asiento, temp->dato.peso);
            temp = temp->siguiente;
        }
        printf("NULL\n");
    }
    else
    {
        printf("La lista está vacía.\n");
    }
}

// Función para imprimir la lista hacia atrás
void imprimirListaAtras(struct Nodo *cabeza)
{
    struct Nodo *temp = cabeza;

    if (cabeza != NULL)
    {
        // Ir al último nodo
        while (temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }

        // Imprimir hacia atrás
        printf("Lista de pasajeros (atrás):\n");
        while (temp != NULL)
        {
            printf("Fila %d, Asiento %c, Peso %.2f kg -> ", temp->dato.fila, temp->dato.asiento, temp->dato.peso);
            temp = temp->anterior;
        }
        printf("NULL\n");
    }
    else
    {
        printf("La lista está vacía.\n");
    }
}

// Función principal
int main()
{
    struct Nodo *lista = NULL;

    struct Pasajero p1 = {1, 'A', 70.5};
    struct Pasajero p2 = {2, 'B', 65.0};
    struct Pasajero p3 = {3, 'C', 80.0};

    agregar(&lista, p1);
    agregar(&lista, p2);
    agregar(&lista, p3);
    
    imprimirListaAdelante(lista);
    imprimirListaAtras(lista);

    modificar(lista, 2, 'B', 68.0);
    imprimirListaAdelante(lista);

    eliminar(&lista, 1, 'A');
    imprimirListaAdelante(lista);
    imprimirListaAtras(lista);

    return 0;
}
