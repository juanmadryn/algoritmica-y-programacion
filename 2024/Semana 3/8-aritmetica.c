#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    for (int i = 0; i < 5; i++) {
        printf("Valor de arr[%d] = %d, Dirección = %p\n", i, *(p + i), (p + i));
    }

    for (int i = 0; i < 5; i++) {
        printf("Valor de arr[%d] = %d, Dirección = %p\n", i, *p, p);
        p++;
    }    

    printf("Cantidad de elementos en arr: %ld\n", &arr[4]-arr+1);


    return 0;
}
