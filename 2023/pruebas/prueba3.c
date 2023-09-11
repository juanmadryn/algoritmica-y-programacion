#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH + 1]; // +1 for null-terminator
    int numWords = 0;
    char sentence[1000];

    printf("Ingrese una oración (ingrese 'fin' para terminar):\n");

    while (1) {
        printf("Oración: ");
        fgets(sentence, sizeof(sentence), stdin);

        // Eliminar el salto de línea al final de la oración
        size_t len = strlen(sentence);
        if (len > 0 && sentence[len - 1] == '\n') {
            sentence[len - 1] = '\0';
        }

        if (strcmp(sentence, "fin") == 0) {
            break;
        }

        char *word = strtok(sentence, " ");

        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, dictionary[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("La palabra '%s' no está en el diccionario. ¿Desea agregarla? (s/n): ", word);
                char response;
                scanf(" %c", &response);

                if (response == 's' || response == 'S') {
                    if (numWords < MAX_WORDS) {
                        strncpy(dictionary[numWords], word, MAX_WORD_LENGTH);
                        dictionary[numWords][MAX_WORD_LENGTH] = '\0'; // Ensure null-termination
                        numWords++;
                        printf("Palabra '%s' agregada al diccionario.\n", word);
                    } else {
                        printf("El diccionario está lleno. No se puede agregar la palabra.\n");
                    }
                }
            }

            word = strtok(NULL, " ");
        }
    }

    printf("\nEstado actual del diccionario:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%d: %s\n", i + 1, dictionary[i]);
    }

    return 0;
}