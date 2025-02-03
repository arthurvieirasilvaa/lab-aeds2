// Exercício 1257 do beecrowd

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, l;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &l);
        int hash = 0;
        
        for(int j = 0; j < l; j++) {
            char str[51];
            scanf("%s", str);
            int tam = strlen(str);
            
            for(int k = 0; k < tam; k++) {
                hash += (str[k] - 'A') + k + j;
            }
        }
        printf("%d\n", hash);
    }

    return 0;
}