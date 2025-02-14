// Exercício 1251 do beecrowd

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elemento {
    int ascii;
    int frequencia;
} Elemento;

int comparacao(const void *a, const void *b) {  
    Elemento *e1 = (Elemento*)a;
    Elemento *e2 = (Elemento*)b;

    if (e1->frequencia != e2->frequencia) {
        return e1->frequencia - e2->frequencia;
    }

    return e2->ascii - e1->ascii;
}

int main() {
    char caracteres[1001];
    int num_caracteres, primeiro = 1;

    while (scanf("%[^\n]", caracteres) != EOF) {
        caracteres[strcspn(caracteres, "\n")] = 0;
        getchar();

        num_caracteres = strlen(caracteres);
        Elemento elementos[256];
        int frequencias[256] = {0};
        int num_elementos = 0;

        for (int i = 0; i < 256; i++) {
            elementos[i].ascii = i;
            elementos[i].frequencia = 0;
        }

        for (int i = 0; i < num_caracteres; i++) {
            int ascii = (unsigned char) caracteres[i];
            if (frequencias[ascii] == 0) {
                num_elementos++;
            }
            frequencias[ascii]++;
        }

        int j = 0;
        for (int i = 0; i < 256; i++) {
            if (frequencias[i] > 0) {
                elementos[j].ascii = i;
                elementos[j].frequencia = frequencias[i];
                j++;
            }
        }

        qsort(elementos, num_elementos, sizeof(Elemento), comparacao);

        if (!primeiro) {
            printf("\n");
        }

        primeiro = 0;

        for (int i = 0; i < num_elementos; i++) {
            printf("%d %d\n", elementos[i].ascii, elementos[i].frequencia);
        }
    }

    return 0;
}