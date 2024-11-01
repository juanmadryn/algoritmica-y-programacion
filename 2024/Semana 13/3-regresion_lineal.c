#include <stdio.h>

// Función para calcular la regresión lineal
void calcular_regresion_lineal(const double x[], const double y[], int n, double *a, double *b) {
    double suma_x = 0, suma_y = 0, suma_xy = 0, suma_x2 = 0;
    
    for (int i = 0; i < n; i++) {
        suma_x += x[i];
        suma_y += y[i];
        suma_xy += x[i] * y[i];
        suma_x2 += x[i] * x[i];
    }
    
    *b = (n * suma_xy - suma_x * suma_y) / (n * suma_x2 - suma_x * suma_x);
    *a = (suma_y - (*b) * suma_x) / n;
}

int main() {
    // Datos de ejemplo
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 5, 4, 5};
    int n = sizeof(x) / sizeof(x[0]);

    double a, b;
    calcular_regresion_lineal(x, y, n, &a, &b);

    printf("La ecuación de la línea de regresión es: y = %.2f + %.2fx\n", a, b);

    // Predicción de un valor, por ejemplo para x = 6
    double x_pred = 6;
    double y_pred = a + b * x_pred;
    printf("Predicción para x = %.2f: y = %.2f\n", x_pred, y_pred);

    return 0;
}