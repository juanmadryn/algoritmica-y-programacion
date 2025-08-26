#include <stdio.h>

int main() {
    int arreglo_multi[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("arreglo_multi[%d][%d] = %d\n", i, j, arreglo_multi[i][j]);
        }
    }

    return 0;
}
