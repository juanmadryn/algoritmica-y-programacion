#include <stdio.h>

float sumar(float numeros[], int cantidad)
{
    if(cantidad == 1){
        return numeros[0];
    }
    return numeros[0] + sumar(&numeros[1], cantidad-1);
}

int main()
{
    float numeros[] = {72.5, 68.0, 80.2, 90.1, 55.3, 60.7};
    printf("%.2f\n", sumar(numeros, 6));
}
