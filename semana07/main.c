#include <stdio.h>
#include <stdlib.h>
#include "linearizada.h"


int main() {
    Matriz m1, m2;
    m1.l = 2;
    m1.c = 2;
    m2.l = 2;
    m2.c = 2;

    criaMatriz(&m1);
    criaMatriz(&m2);


    alteraElementoNaMatriz(&m1, 0, 0, 1);
    alteraElementoNaMatriz(&m1, 0, 1, 2);
    alteraElementoNaMatriz(&m1, 1, 0, 3);
    alteraElementoNaMatriz(&m1, 1, 1, 4);
    alteraElementoNaMatriz(&m2, 0, 0, 5);
    alteraElementoNaMatriz(&m2, 0, 1, 6);
    alteraElementoNaMatriz(&m2, 1, 0, 7);
    alteraElementoNaMatriz(&m2, 1, 1, 8);
    
    imprimeMatriz(&m1);
    imprimeMatriz(&m2);

    printf("Elemento na posição [0][1] de m1: %d\n", consultaElementoNaMatriz(&m1, 0, 1));
    printf("Elemento na posição [1][1] de m1: %d\n", consultaElementoNaMatriz(&m1, 1, 1));

    Matriz *soma = (Matriz*) malloc(sizeof(Matriz));
    // Verificando se a memória foi alocada corretamente:
    if(soma == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    soma = somaMatrizes(&m1, &m2);
    printf("Soma das matrizes m1 e m2:\n");
    imprimeMatriz(soma);

    Matriz *transposta = (Matriz*) malloc(sizeof(Matriz));
    // Verificando se a memória foi alocada corretamente:
    if(transposta == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    transposta = getTransporta(&m1);
    printf("Transposta da matriz m1:\n");
    imprimeMatriz(transposta);

    transposta = getTransporta(&m2);
    printf("Transposta da matriz m2:\n");
    imprimeMatriz(transposta);

    apagaMatriz(&m1);
    apagaMatriz(&m2);
    free(soma);
    free(transposta);

    return 0;
}