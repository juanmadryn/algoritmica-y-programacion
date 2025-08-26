#include <stdio.h>

int main() {
    short shortInteger = 32000;
    long longInteger = 20000000000001234578;
    unsigned int unsignedInteger = 4000000000U;

    printf("short: %d\n", shortInteger);
    printf("long: %ld\n", longInteger);
    printf("unsigned int: %u\n", unsignedInteger);

    return 0;
}
