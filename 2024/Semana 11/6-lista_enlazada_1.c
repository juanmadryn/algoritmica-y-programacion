#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

struct Nodo *crearNodo(int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregar(struct Nodo **cabeza, int valor)
{
    struct Nodo *nuevoNodo = crearNodo(valor);

    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
    }
    else
    {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Elemento %d agregado a la lista.\n", valor);
}

void eliminar(struct Nodo **cabeza, int valor)
{
    struct Nodo *temp = *cabeza;
    struct Nodo *prev = NULL;

    if (*cabeza == NULL)
    {
        printf("La lista está vacía.\n");
        return;
    }

    // Si el nodo a eliminar es la cabeza
    if (temp != NULL && temp->dato == valor)
    {
        *cabeza = temp->siguiente;
        free(temp);
        printf("Elemento %d eliminado de la lista.\n", valor);
        return;
    }

    // Buscar el nodo a eliminar
    while (temp != NULL && temp->dato != valor)
    {
        prev = temp;
        temp = temp->siguiente;
    }

    // Si el valor está en la lista
    if (temp != NULL)
    {
        // Desenlazar el nodo
        prev->siguiente = temp->siguiente;
        free(temp);
        printf("Elemento %d eliminado de la lista.\n", valor);
    }
    else
    {
        printf("Elemento %d no encontrado en la lista.\n", valor);
    }
}

void modificar(struct Nodo *cabeza, int valorAntiguo, int valorNuevo)
{
    struct Nodo *temp = cabeza;

    // Buscar el nodo con el valor a modificar
    while (temp != NULL && temp->dato != valorAntiguo)
    {
        temp = temp->siguiente;
    }

    // Si el valor está en la lista
    if (temp != NULL)
    {
        // Modificar el valor
        temp->dato = valorNuevo;
        printf("Elemento %d modificado a %d en la lista.\n", valorAntiguo, valorNuevo);
    }
    else
    {
        printf("Elemento %d no encontrado en la lista.\n", valorAntiguo);
    }
}

void imprimirLista(struct Nodo *cabeza)
{
    struct Nodo *temp = cabeza;

    if (cabeza == NULL)
    {
        printf("La lista está vacía.\n");
        return;
    }

    printf("Elementos de la lista: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int main()
{
    struct Nodo *lista = NULL;

    agregar(&lista, 10);
    agregar(&lista, 20);
    agregar(&lista, 30);
    imprimirLista(lista);

    modificar(lista, 20, 25);
    imprimirLista(lista);

    eliminar(&lista, 10);
    imprimirLista(lista);

    agregar(&lista,40);
    imprimirLista(lista);

    eliminar(&lista, 40);
    imprimirLista(lista);

    return 0;
}
