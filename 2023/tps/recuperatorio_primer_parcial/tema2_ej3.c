#include <stdio.h>
#define DEBUG

float mediana(int arr[], int tam)
{
    float mediana = 0.0;
    if(tam % 2 == 0) {
        #ifdef DEBUG
            printf("%d, %d\n", arr[tam/2-1], arr[tam/2]);
        #endif
        mediana = (arr[tam/2-1] + arr[tam/2])/2.0;
    } else {
        mediana = arr[tam/2];
    }
    return mediana;
}

int main(){
    int arreglo[10] = {1,3,3,6,7,8,9,9,10,12};
    
    float medianaV = mediana(arreglo, 10);

    printf("Mediana: %f", medianaV);
    return 0;
}