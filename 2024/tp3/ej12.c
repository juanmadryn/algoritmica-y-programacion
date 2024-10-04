#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 100

// Enumeración para tipo de unidad
enum TipoUnidad {
    UNIDADES,
    KILOS_LITROS
};

// Unión para stock
union Stock {
    int unidades;
    float kilos_litros;
};

// Estructura para producto
struct Producto {
    char codigo[10];
    char nombre[50];
    enum TipoUnidad tipo_unidad;
    union Stock stock;
    float precio;
};

// Función para agregar un producto
void agregarProducto(struct Producto catalogo[], int *cantidad) {
    if (*cantidad >= MAX_PRODUCTOS) {
        printf("Error: Catalogo lleno.\n");
        return;
    }

    struct Producto producto;
    printf("Ingrese codigo: ");
    scanf("%s", producto.codigo);

    // Verificar si el codigo ya existe
    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(catalogo[i].codigo, producto.codigo) == 0) {
            printf("Error: Codigo ya existe.\n");
            return;
        }
    }

    printf("Ingrese nombre: ");
    scanf(" %s", producto.nombre);

    printf("Ingrese tipo de unidad (1 para unidades, 2 para kilos/litros): ");
    int opcion;
    scanf("%d", &opcion);
    if (opcion == 1) {
        producto.tipo_unidad = UNIDADES;
    } else if (opcion == 2) {
        producto.tipo_unidad = KILOS_LITROS;
    } else {
        printf("Error: Opcion invalida.\n");
        return;
    }

    if (producto.tipo_unidad == UNIDADES) {
        printf("Ingrese stock en unidades: ");
        scanf("%d", &producto.stock.unidades);
    } else {
        printf("Ingrese stock en kilos/litros: ");
        scanf("%f", &producto.stock.kilos_litros);
    }

    printf("Ingrese precio: ");
    scanf("%f", &producto.precio);

    catalogo[*cantidad] = producto;
    (*cantidad)++;
    printf("Producto agregado con exito.\n");
}

// Función para buscar un producto por nombre exacto
void buscarProducto(struct Producto catalogo[], int cantidad) {
    char nombre[50];
    printf("Ingrese nombre del producto: ");
    scanf(" %s", nombre);

    for (int i = 0; i < cantidad; i++) {
        if (strcasecmp(catalogo[i].nombre, nombre) == 0) {
            printf("Codigo: %s\n", catalogo[i].codigo);
            printf("Nombre: %s\n", catalogo[i].nombre);
            if (catalogo[i].tipo_unidad == UNIDADES) {
                printf("Stock: %d unidades\n", catalogo[i].stock.unidades);
            } else {
                printf("Stock: %.2f kilos/litros\n", catalogo[i].stock.kilos_litros);
            }
            printf("Precio: %.2f\n", catalogo[i].precio);
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

// Función para imprimir el catalogo
void imprimirCatalogo(struct Producto catalogo[], int cantidad) {
    printf("Catalogo de productos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Codigo: %s\n", catalogo[i].codigo);
        printf("Nombre: %s\n", catalogo[i].nombre);
        if (catalogo[i].tipo_unidad == UNIDADES) {
            printf("Stock: %d unidades\n", catalogo[i].stock.unidades);
        } else {
            printf("Stock: %.2f kilos/litros\n", catalogo[i].stock.kilos_litros);
        }
        printf("Precio: %.2f\n\n", catalogo[i].precio);
    }
}

int main() {
    struct Producto catalogo[MAX_PRODUCTOS];
    int cantidad = 0;

    int opcion;
    do {
        printf("1. Agregar producto\n");
        printf("2. Buscar producto\n");
        printf("3. Imprimir catalogo\n");
        printf("4. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(catalogo, &cantidad);
                break;
            case 2:
                buscarProducto(catalogo, cantidad);
                break;
            case 3:
                imprimirCatalogo(catalogo, cantidad);
                break;
            case 4:
                printf("Adios.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
