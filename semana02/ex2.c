#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    int b;
    
    if(&a > &b) {
        printf("%p\n", &a);
    }
    else {
        printf("%p\n", &b);
    }
    
    return 0;
}