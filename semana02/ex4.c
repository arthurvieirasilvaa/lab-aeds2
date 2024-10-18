#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 34, j;
    int * p ;
    
    p = &i ;
    (*p)++;
    j = *p + 33;
    
    printf("i = %d\n", i);
    printf("p = %d\n", *p);
    printf("j = %d\n", j);
    
    return 0;
}
