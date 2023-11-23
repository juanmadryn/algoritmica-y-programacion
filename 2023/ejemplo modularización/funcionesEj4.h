// Definición de la estructura para un producto
struct Producto {
    char codigo[10];
    char nombre[50];
    int stock;
    float precio;
};

// Función para agregar un producto al catálogo
void agregarProducto(struct Producto catalogo[], int *numProductos);

// Función para modificar un producto existente
void modificarProducto(struct Producto catalogo[], int numProductos);

// Función para buscar un producto por su nombre
void buscarProductoPorNombre(struct Producto catalogo[], int numProductos);

// Función para eliminar un producto por su código
void eliminarProducto(struct Producto catalogo[], int *numProductos);

// Función para imprimir todo el catálogo
void imprimirCatalogo(struct Producto catalogo[], int numProductos);