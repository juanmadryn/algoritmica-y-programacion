#include <stdio.h>
#define TABLE_SIZE 10  // Tamaño de la tabla hash

// Función de hash simple
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insertar un valor en la tabla hash
void insert(int table[], int key) {
    int index = hash(key);  // Calcular índice usando función hash
    
    // Manejar colisiones: se desplaza hacia adelante en caso de ocupación
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    
    table[index] = key;  // Insertar la clave en la tabla hash
}

// Imprimir la tabla hash
void printTable(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1) {
            printf("Índice %d: %d\n", i, table[i]);
        } else {
            printf("Índice %d: -\n", i);
        }
    }
}

int main() {
    // Inicializar la tabla hash con -1 para indicar posiciones vacías
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insertar algunos valores en la tabla hash
    int keys[] = {15, 25, 35, 8, 12, 5, 20, 33, 10, 5};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Imprimir la tabla hash
    printf("Tabla Hash:\n");
    printTable(hashTable);

    return 0;
}
