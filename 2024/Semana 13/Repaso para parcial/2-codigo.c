#include <stdio.h>
int main() {
    char *n = "algo.txt";
    FILE *a = fopen(n, "r");
    int l = 0, u = 0;
    char c;
    while ((c = fgetc(a)) != EOF) {
        if (c == '\n') {
            l++;
            u = 1;
        } else {
            u = 0;
        }
    }
    if(!u){
        l++;
    }
    fclose(a);
    printf("%d.\n", l);
}