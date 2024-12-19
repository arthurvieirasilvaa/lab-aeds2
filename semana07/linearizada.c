#include <stdio.h>
#include <stdlib.h>
#include "linearizada.h"


void criaMatriz(Matriz *m) {
    m->data = (int*) malloc(m->l * m->c * sizeof(int));
    
    // Verificando se a memória foi alocada corretamente:
    if(m->data == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
}


void apagaMatriz(Matriz *m) {
    free(m->data);
    m->data = NULL;
}


void alteraElementoNaMatriz(Matriz *m, int lin, int col, int valor) {
    if(lin < 0 && lin >= m->l && col < 0 && col >= m->c) {
        printf("Posição inválida na matriz!\n");
        exit(1);
    }

    else {
        // Obtendo a posição do elemento:
        int index = lin * m->c + col;

        m->data[index] = valor;
    }
}


int consultaElementoNaMatriz(Matriz *m, int lin, int col) {
    if(lin < 0 && lin >= m->l && col < 0 && col >= m->c) {
        printf("Posição inválida na matriz!\n");
        exit(1);
    }

    else {
        // Obtendo a posição do elemento:
        int index = lin * m->c + col;
        return m->data[index];
    }
}


void imprimeMatriz(Matriz *m) {
    int index;
    for(int i = 0; i < m->l; i++) {
        for(int j = 0; j < m->c; j++) {
            // Obtendo a posição do elemento:
            index = i * m->c + j;
            printf("%d ", m->data[index]);
        }
        printf("\n");
    }
    printf("\n");
}


Matriz* getTransporta(Matriz *m) {
    Matriz *transposta = (Matriz*) malloc(sizeof(Matriz));
    // Verificando se a memória foi alocada corretamente:
    if(transposta == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    transposta->l = m->c;
    transposta->c = m->l;
    criaMatriz(transposta);

    int index_m, index_transposta;
    for(int i = 0; i < m->l; i++) {
        for(int j = 0; j < m->c; j++) {
            // Obtendo a posição do elemento na matriz m:
            index_m = i * m->c + j;
            // Obtendo a posição do elemento na matriz transposta:
            index_transposta = j * m->l + i;
            transposta->data[index_transposta] = m->data[index_m];
        }
    }

    return transposta;
}


Matriz* somaMatrizes(Matriz *m1, Matriz *m2) {
    if(m1->l != m2->l || m1->c != m2->c) {
        printf("As dimensões das duas matrizes são diferentes!\n");
        exit(1);
    }

    Matriz *soma = (Matriz*) malloc(sizeof(Matriz));
    // Verificando se a memória foi alocada corretamente:
    if(soma == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    soma->l = m1->l;
    soma->c = m2->c;
    criaMatriz(soma);
    
    int index;
    for(int i = 0; i < soma->l; i++) {
        for(int j = 0; j < soma->c; j++) {
            // Obtendo a posição do elemento:
            index = i * m1->c + j;
            soma->data[index] = m1->data[index] + m2->data[index];
        }
    }
    
    return soma;
}
