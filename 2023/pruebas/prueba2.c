#include <stdio.h>

#define ITERATIONS 10


int main(){
    int a = 5;
    for(int i = 0; i < ITERATIONS; i++){
        a += i;
    }
    printf("A1: %d\n", a);

    a = 5;
    int i = 0;
    while(i++ < ITERATIONS){
        a += i;
    }
    printf("A2: %d\n", a);

    a = 5;
    i = 0;
    do {
        a += i;
    } while(i++ < ITERATIONS);
    printf("A3: %d\n", a);
}