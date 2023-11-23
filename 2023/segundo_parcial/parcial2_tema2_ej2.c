#include <stdio.h>
#include <stdlib.h>
int main() {
	int *numeros = malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		*(numeros+i) = i * i;
		printf("%d ", numeros[i]);
	}
	free(numeros);
	return 0;
}