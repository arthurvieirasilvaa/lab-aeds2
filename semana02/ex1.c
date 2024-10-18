#include <stdio.h>
#include <stdlib.h>

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd) {
    int *x3 = (int*) malloc(n1+n2 * sizeof(int));
    x3[0] = x1[0];
    (*qtd) = 1;
    
    for(int i = 1; i < n1; i++) {
        if(x1[i] != x3[(*qtd)-1]) {
            x3[(*qtd)] = x1[i];
            (*qtd)++;
        }
    }

    for(int i = 0; i < n2; i++) {
        if(x1[i] != x2[i]) {
            x3[(*qtd)] = x2[i];
            (*qtd)++;
        }
    }
    
    return x3;
}

int main() {
    int n1 = 5;
    int n2 = 5;
    int qtd;
    int x1[] = {1, 3, 3, 7, 8};
    int x2[] = {1, 3, 4, 6, 8};
    
    int *x3 = uniao(x1, x2, n1, n2, &qtd);

    printf("x1 = ");
    for(int i = 0; i < n1; i++) {
        printf("%d ", x1[i]);
    }
    printf("\n");

    printf("x2 = ");
    for(int i = 0; i < n2; i++) {
        printf("%d ", x2[i]);
    }
    printf("\n");

    printf("x3 = ");
    for(int i = 0; i < qtd; i++) {
        printf("%d ", x3[i]);
    }
    printf("\n");

    return 0;
}