#include <stdio.h>
#include <string.h>

#include "funcionesEj4.h"

#define SALIR 9

int main() {
    struct Producto catalogo[100]; // Catálogo de productos (hasta 100 productos)
    int numProductos = 0; // Número actual de productos en el catálogo
    int opcion;
    
    do {
        printf("\nMenú:\n");
        printf("1. Agregar un producto\n");
        printf("2. Modificar un producto\n");
        printf("3. Buscar un producto por nombre\n");
        printf("4. Eliminar un producto\n");
        printf("5. Imprimir todo el catálogo\n"); // Nueva opción
        printf("%d. Salir\n", SALIR);
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarProducto(catalogo, &numProductos);
                break;
            case 2:
                modificarProducto(catalogo, numProductos);
                break;
            case 3:
                buscarProductoPorNombre(catalogo, numProductos);
                break;
            case 4:
                eliminarProducto(catalogo, &numProductos);
                break;
            case 5:
                imprimirCatalogo(catalogo, numProductos); // Llamamos a la nueva función
                break;
            case SALIR:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != SALIR);
    
    return 0;
}