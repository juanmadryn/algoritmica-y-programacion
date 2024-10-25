#include <stdio.h>
#include <stdlib.h>
#include "archivo_configuracion.h"

#define FILAS 17
#define ASIENTOS 6

typedef struct
{
    int fila;
    char asiento;
    float peso;
} Pasajero;

typedef struct
{
    Pasajero dato;
    Nodo *anterior;
    Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo con un pasajero
Nodo *crearNodo(Pasajero pasajero)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->dato = pasajero;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para agregar un pasajero a la lista
void agregar(Nodo **cabeza, Pasajero pasajero)
{
    Nodo *nuevoNodo = crearNodo(pasajero);

    // La lista está vacía, el nuevo nodo es la cabeza
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
    }
    // la lista NO está vacía, el nuevo nodo va al final
    else
    {
        Nodo *temp = *cabeza;
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
void eliminar(Nodo **cabeza, int fila, char asiento)
{
    Nodo *temp = *cabeza;

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
void modificar(Nodo *cabeza, int fila, char asiento, float nuevoPeso)
{
    Nodo *temp = cabeza;

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
void imprimirListaAdelante(Nodo *cabeza)
{
    Nodo *temp = cabeza;

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
void imprimirListaAtras(Nodo *cabeza)
{
    Nodo *temp = cabeza;

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

void ingresarPeso(Nodo **cabeza)
{
    int fila;
    char asiento;
    float peso;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    printf("Ingresa el asiento (A-F): ");
    scanf(" %c", &asiento);
    if (asiento < 'A' || asiento > 'F')
    {
        printf("Letra de asiento inválida.\n");
        return;
    }

    printf("Ingresa el peso: ");
    scanf("%f", &peso);

    Pasajero pasajero;
    pasajero.fila = fila;
    pasajero.asiento = asiento;
    pasajero.peso = peso;

    agregar(cabeza, pasajero);
}

void borrarPeso(Nodo **cabeza)
{
    int fila;
    char asiento;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    printf("Ingresa el asiento (A-F): ");
    scanf(" %c", &asiento);
    if (asiento < 'A' || asiento > 'F')
    {
        printf("Letra de asiento inválida.\n");
        return;
    }

    int indice = calcularIndice(fila, asiento);
    pasajero.peso = 0.0;

    printf("Peso borrado correctamente.\n");
}

void mostrarPesoFila(Nodo **cabeza)
{
    int fila;
    float pesoTotal = 0.0;

    printf("Ingresa la fila (1-17): ");
    scanf("%d", &fila);
    if (fila < 1 || fila > FILAS)
    {
        printf("Número de fila inválido.\n");
        return;
    }

    for (char asiento = 'A'; asiento <= 'F'; asiento++)
    {
        int indice = calcularIndice(fila, asiento);
        pesoTotal += pasajero.peso;
    }

    printf("El peso total de la fila %d es: %.2f kg\n", fila, pesoTotal);
}

void mostrarPesoTotal(Nodo **cabeza)
{
    float pesoTotal = 0.0;

    for (int i = 0; i < TOTAL_PASAJEROS; i++)
    {
        pesoTotal += pasajeros[i].peso;
    }

    printf("El peso total de los pasajeros del avión es: %.2f kg\n", pesoTotal);
}

void guardarEnArchivo(Pasajero pasajeros[TOTAL_PASAJEROS], const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < TOTAL_PASAJEROS; i++)
    {
        if (pasajeros[i].peso > 0)
        {
            fwrite(&pasajeros[i], sizeof(Pasajero), 1, archivo);
        }
    }

    fclose(archivo);
    printf("Datos guardados en el archivo '%s' correctamente.\n", nombreArchivo);
}

void importarDesdeArchivo(Pasajero pasajeros[TOTAL_PASAJEROS], const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Pasajero pasajero;
    while (fread(&pasajero, sizeof(Pasajero), 1, archivo) == 1)
    {
        int indice = calcularIndice(pasajero.fila, pasajero.asiento);
        pasajero.fila = pasajero.fila;
        pasajero.asiento = pasajero.asiento;
        pasajero.peso = pasajero.peso;
    }

    fclose(archivo);
    printf("Datos importados desde el archivo '%s' correctamente.\n", nombreArchivo);
}

int main()
{
    Pasajero pasajeros[TOTAL_PASAJEROS] = {0};
    int opcion;
    char *nombreArchivo = obtenerValorConfiguracion("archivo_datos");
    importarDesdeArchivo(pasajeros, nombreArchivo);

    do
    {
        printf("\nMenú:\n");
        printf("1. Ingresar un peso nuevo\n");
        printf("2. Borrar un peso\n");
        printf("3. Mostrar el peso de una fila\n");
        printf("4. Mostrar el peso total de los pasajeros del avión\n");
        printf("5. Terminar el programa\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarPeso(pasajeros);
            guardarEnArchivo(pasajeros, nombreArchivo);
            break;
        case 2:
            borrarPeso(pasajeros);
            guardarEnArchivo(pasajeros, nombreArchivo);
            break;
        case 3:
            mostrarPesoFila(pasajeros);
            break;
        case 4:
            mostrarPesoTotal(pasajeros);
            break;
        case 5:
            printf("Terminando el programa.\n");
            break;
        default:
            printf("Opción inválida. Inténtalo nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}

// Función principal
int main()
{
    Nodo *lista = NULL;

    Pasajero p1 = {1, 'A', 70.5};
    Pasajero p2 = {2, 'B', 65.0};
    Pasajero p3 = {3, 'C', 80.0};

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
