#include <stdio.h>
#include <stdlib.h>

#include "csr.h"


void criaMatriz(Matriz *m) {
    m->data = (int*) malloc(m->Nz * sizeof(int));

    // Verificando se a memória foi alocada corretamente:
    if(m->data == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    m->jr = (int*) malloc(m->Nz * sizeof(int));
    if(m->data == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    m->jc = (int*) malloc((m->l + 1) * sizeof(int));
    if(m->data == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
}


void apagaMatriz(Matriz *m) {
    free(m->data);
    m->data = NULL;
    free(m->jr);
    m->jr = NULL;
    free(m->jc);
    m->jc = NULL;
}


void alteraElementoNaMatriz(Matriz *m, int lin, int col, int valor) {
    int inicio = m->jc[lin];
    int fim = m->jc[lin + 1];

    for (int i = inicio; i < fim; i++) {
        // Se a coluna já está no vetor 'jr', o elemento é substituído:
        if (m->jr[i] == col) {
            m->data[i] = valor;
            return;
        }
    }

    m->Nz++;
    m->data = realloc(m->data, m->Nz * sizeof(int));
    m->jr = realloc(m->jr, m->Nz * sizeof(int));

    m->data[m->Nz - 1] = valor;
    m->jr[m->Nz - 1] = col;

    for (int i = lin + 1; i <= m->l; i++) {
        m->jc[i]++;
    }
}


int consultaElementoNaMatriz(Matriz *m, int lin, int col) {
    // Procurar a linha e a coluna para retornar o valor
    int inicio = m->jc[lin];
    int fim = m->jc[lin + 1];

    for (int i = inicio; i < fim; i++) {
        if (m->jr[i] == col) {
            return m->data[i];
        }
    }
    return 0;
}


void imprimeMatriz(Matriz *m) {
    int numero;
    for (int i = 0; i < m->l; i++) {
        for (int j = 0; j < m->c; j++) {
            // Obtendo o número na posição em i, j:
            numero = consultaElementoNaMatriz(m, i, j);
            printf("%d ", numero);
        }
        printf("\n");
    }
    printf("\n");
}


Matriz* getTransporta(Matriz *m) {
    Matriz *transposta = (Matriz*) malloc(sizeof(Matriz));
    transposta->l = m->c;
    transposta->c = m->l;
    transposta->Nz = m->Nz;

    criaMatriz(transposta);

    int linha, coluna;
    for (int i = 0; i < m->Nz; i++) {
        linha = m->jr[i];
        coluna = m->jr[i];
        alteraElementoNaMatriz(transposta, coluna, linha, m->data[i]);
    }

    return transposta;
}


Matriz* somaMatrizes(Matriz *m1, Matriz *m2) {
    if (m1->l != m2->l || m1->c != m2->c) {
        printf("As matrizes devem ter as mesmas dimensões.\n");
        exit(1);
    }

    Matriz *soma = (Matriz*) malloc(sizeof(Matriz));
    soma->l = m1->l;
    soma->c = m1->c;
    soma->Nz = 0;
    criaMatriz(soma);

    int inicio1, fim1;
    int inicio2, fim2;
    int j1, j2;
    
    for(int i = 0; i < m1->l; i++) {
        inicio1 = m1->jc[i];
        fim1 = m1->jc[i + 1];
        
        inicio2 = m2->jc[i];
        fim2 = m2->jc[i + 1];

        j1 = inicio1;
        j2 = inicio2;
        
        while(j1 < fim1 && j2 < fim2) {
            if(m1->jr[j1] == m2->jr[j2]) {
                int sum = m1->data[j1] + m2->data[j2];
                alteraElementoNaMatriz(soma, i, m1->jr[j1], sum);
                j1++;
                j2++;
            } 
            
            else if (m1->jr[j1] < m2->jr[j2]) {
                alteraElementoNaMatriz(soma, i, m1->jr[j1], m1->data[j1]);
                j1++;
            } 
            
            else {
                alteraElementoNaMatriz(soma, i, m2->jr[j2], m2->data[j2]);
                j2++;
            }
        }

        while(j1 < fim1) {
            alteraElementoNaMatriz(soma, i, m1->jr[j1], m1->data[j1]);
            j1++;
        }

        while(j2 < fim2) {
            alteraElementoNaMatriz(soma, i, m2->jr[j2], m2->data[j2]);
            j2++;
        }
    }

    return soma;
}
