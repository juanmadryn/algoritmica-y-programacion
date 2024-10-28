#include <stdio.h>

void entregarDineroMinBilletes(int monto) {
    int denominaciones[] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int cantidadDenominaciones = sizeof(denominaciones) / sizeof(denominaciones[0]);

    printf("Monto a entregar: %d\n", monto);
    printf("Billetes y monedas usados:\n");

    for (int i = 0; i < cantidadDenominaciones; i++) {
        int cantidad = monto / denominaciones[i];
        if (cantidad > 0) {
            printf("%d x %d\n", cantidad, denominaciones[i]);
            monto -= cantidad * denominaciones[i];
        }
    }
}

int main() {
    int monto;

    printf("Ingrese el monto a entregar: ");
    scanf("%d", &monto);

    entregarDineroMinBilletes(monto);

    return 0;
}
