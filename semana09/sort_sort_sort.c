// Exercício 1252 do beecrowd

#include <stdio.h>
#include <stdlib.h>

int n, m;

int comparacao(const void *a, const void *b) {
    int *n1 = (int*)a;
    int *n2 = (int*)b;

    int modulo1;
    int modulo2;

    if(*n1 < 0) {
        modulo1 = -(abs(*n1) % m); 
    }
    
    else {
        modulo1 = *n1 % m;
    }

    if(*n2 < 0) {
        modulo2 = -(abs(*n2) % m); 
    }
    
    else {
        modulo2 = *n2 % m;
    }

    if (modulo1 != modulo2) {
        return modulo1 - modulo2;
    }

    if ((*n1 % 2 != 0) && (*n2 % 2 == 0)) {
        return -1;
    }

    if ((*n1 % 2 == 0) && (*n2 % 2 != 0)) {
        return 1;
    }

    if (*n1 % 2 != 0 && *n2 % 2 != 0) {
        return *n2 - *n1;
    }

    return *n1 - *n2;
}

int main() {
    scanf("%d %d", &n, &m);

    while(n != 0 && m != 0) {
    
        int numeros[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &numeros[i]);
        }

        qsort(numeros, n, sizeof(int), comparacao);

        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i++) {
            printf("%d\n", numeros[i]);
        }

        scanf("%d %d", &n, &m);
    }

    printf("0 0\n");

    return 0;
}
