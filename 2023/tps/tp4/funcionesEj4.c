#include <stdio.h>
#include <string.h>

// Definición de la estructura para un producto
struct Producto {
    char codigo[10];
    char nombre[50];
    int stock;
    float precio;
};

// Función para agregar un producto al catálogo
void agregarProducto(struct Producto catalogo[], int *numProductos) {
    struct Producto nuevoProducto;
    
    printf("Ingrese el código del producto: ");
    scanf("%s", nuevoProducto.codigo);
    
    // Verificar si el producto ya existe en el catálogo
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nuevoProducto.codigo, catalogo[i].codigo) == 0) {
            printf("El código del producto ya existe en el catálogo.\n");
            return;
        }
    }
    
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevoProducto.nombre);
    
    printf("Ingrese el stock del producto: ");
    scanf("%d", &nuevoProducto.stock);
    
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);
    
    catalogo[*numProductos] = nuevoProducto;
    (*numProductos)++;
    printf("Producto agregado al catálogo con éxito.\n");
}

// Función para modificar un producto existente
void modificarProducto(struct Producto catalogo[], int numProductos) {
    char codigoBuscado[10];
    
    printf("Ingrese el código del producto que desea modificar: ");
    scanf("%s", codigoBuscado);
    
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(codigoBuscado, catalogo[i].codigo) == 0) {
            // Mostrar los valores originales antes de la modificación
            printf("Valores originales:\n");
            printf("Nombre: %s\n", catalogo[i].nombre);
            printf("Stock: %d\n", catalogo[i].stock);
            printf("Precio: %.2f\n", catalogo[i].precio);
            
            // Solicitar las modificaciones
            printf("Ingrese el nuevo nombre del producto (o presione Enter para dejarlo sin cambios): ");
            scanf(" %[^\n]", catalogo[i].nombre);
            
            printf("Ingrese el nuevo stock del producto (o -1 para dejarlo sin cambios): ");
            scanf("%d", &catalogo[i].stock);
            
            if (catalogo[i].stock == -1) {
                // Dejar el stock sin cambios
                catalogo[i].stock = catalogo[i].stock;
            }
            
            printf("Ingrese el nuevo precio del producto (o -1.0 para dejarlo sin cambios): ");
            scanf("%f", &catalogo[i].precio);
            
            if (catalogo[i].precio == -1.0) {
                // Dejar el precio sin cambios
                catalogo[i].precio = catalogo[i].precio;
            }
            
            printf("Producto modificado con éxito.\n");
            return;
        }
    }
    
    printf("No se encontró ningún producto con ese código.\n");
}

// Función para buscar un producto por su nombre
void buscarProductoPorNombre(struct Producto catalogo[], int numProductos) {
    char nombreBuscado[50];
    
    printf("Ingrese el nombre del producto que desea buscar: ");
    scanf(" %[^\n]", nombreBuscado);
    
    printf("Resultados de la búsqueda:\n");
    for (int i = 0; i < numProductos; i++) {
        if (strstr(catalogo[i].nombre, nombreBuscado) != NULL) {
            printf("Código: %s\n", catalogo[i].codigo);
            printf("Nombre: %s\n", catalogo[i].nombre);
            printf("Stock: %d\n", catalogo[i].stock);
            printf("Precio: %.2f\n", catalogo[i].precio);
            printf("\n");
        }
    }
}

// Función para eliminar un producto por su código
void eliminarProducto(struct Producto catalogo[], int *numProductos) {
    char codigoEliminar[10];
    
    printf("Ingrese el código del producto que desea eliminar: ");
    scanf("%s", codigoEliminar);
    
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(codigoEliminar, catalogo[i].codigo) == 0) {
            // Mover el último producto al lugar del producto a eliminar
            catalogo[i] = catalogo[(*numProductos) - 1];
            (*numProductos)--;
            printf("Producto eliminado con éxito.\n");
            return;
        }
    }
    
    printf("No se encontró ningún producto con ese código.\n");
}

// Función para imprimir todo el catálogo
void imprimirCatalogo(struct Producto catalogo[], int numProductos) {
    printf("Catálogo de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Código: %s\n", catalogo[i].codigo);
        printf("Nombre: %s\n", catalogo[i].nombre);
        printf("Stock: %d\n", catalogo[i].stock);
        printf("Precio: %.2f\n", catalogo[i].precio);
        printf("\n");
    }
}