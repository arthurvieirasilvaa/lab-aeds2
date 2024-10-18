#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 7, j = 5, c;
    int *p;
    int **q;
    
    p = &i;
    q = &p;
    c = **q + j;
    
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("c = %d\n", c);
    printf("p = %d\n", *p);
    printf("q = %d\n", **q);
    
    return 0;
}