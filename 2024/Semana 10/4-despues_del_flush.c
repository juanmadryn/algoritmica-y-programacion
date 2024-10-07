#include <stdio.h>

int main() {
    FILE *archivo;
    int numero;

    // Abrir archivo para escribir en modo texto
    archivo = fopen("numeros.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        // Pedir al usuario que ingrese un número
        printf("Ingresa un número entero: ");
        scanf("%d", &numero);

        // Escribir el número en el archivo
        fprintf(archivo, "%d\n", numero);

        // Forzar la escritura inmediata al archivo
        fflush(archivo);

        // Esperar a que el usuario presione una tecla
        printf("Presiona cualquier tecla para continuar...\n");
        getchar();  // Captura el '\n' que deja scanf
        getchar();  // Espera la entrada del usuario
    }

    // Cerrar el archivo
    fclose(archivo);
    printf("Números guardados en el archivo.\n");

    return 0;
}
