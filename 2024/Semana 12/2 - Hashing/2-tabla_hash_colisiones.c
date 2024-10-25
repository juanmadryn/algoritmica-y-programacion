#include <stdio.h>
#define TABLE_SIZE 10  // Tamaño de la tabla hash
#define MAX_COLLISIONS 10  // Máximo de colisiones permitidas por índice

// Estructura para cada índice de la tabla hash que contiene hasta MAX_COLLISIONS valores
typedef struct {
    int values[MAX_COLLISIONS];
    int count;  // Cuenta de valores almacenados en este índice
} HashBucket;

// Función de hash simple
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insertar un valor en la tabla hash con manejo de colisiones
void insert(HashBucket table[], int key) {
    int index = hash(key);

    if (table[index].count < MAX_COLLISIONS) {
        table[index].values[table[index].count] = key;
        table[index].count++;
        printf("Clave %d insertada en índice %d\n", key, index);
    } else {
        printf("Índice %d lleno; no se puede insertar la clave %d.\n", index, key);
    }
}

// Imprimir la tabla hash
void printTable(HashBucket table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d:", i);
        for (int j = 0; j < table[i].count; j++) {
            printf(" %d", table[i].values[j]);
        }
        if (table[i].count == 0) {
            printf(" - vacío -");
        }
        printf("\n");
    }
}

int main() {
    // Inicializar la tabla hash
    HashBucket hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].count = 0;  // Inicializar cuenta de valores en 0
    }

    // Insertar algunos valores en la tabla hash
    int keys[] = {15, 25, 35, 8, 12, 5, 20, 30, 40, 7, 3, 14};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Imprimir la tabla hash
    printf("Tabla Hash:\n");
    printTable(hashTable);

    return 0;
}
