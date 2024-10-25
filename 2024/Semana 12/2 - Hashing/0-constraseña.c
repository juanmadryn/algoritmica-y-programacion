#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE SHA256_DIGEST_LENGTH

// Función para hacer el hash de una contraseña
void hashPassword(const char *password, unsigned char *hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
}

// Función para imprimir el hash en formato hexadecimal
void printHash(const unsigned char *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Función para verificar si dos hashes coinciden
int verifyPassword(const unsigned char *hash1, const unsigned char *hash2) {
    return memcmp(hash1, hash2, HASH_SIZE) == 0;
}

int main() {
    char password[256];
    unsigned char storedHash[HASH_SIZE];
    unsigned char inputHash[HASH_SIZE];

    // Solicitar la contraseña y hacer hashing para almacenamiento
    printf("Ingrese una contraseña para almacenar: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Eliminar salto de línea

    hashPassword(password, storedHash);
    printf("Hash de la contraseña almacenada: ");
    printHash(storedHash);

    // Solicitar la contraseña nuevamente para verificación
    printf("Ingrese la contraseña nuevamente para verificación: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Eliminar salto de línea

    hashPassword(password, inputHash);

    // Verificar si los hashes coinciden
    if (verifyPassword(storedHash, inputHash)) {
        printf("La contraseña es correcta.\n");
    } else {
        printf("La contraseña es incorrecta.\n");
    }

    return 0;
}
