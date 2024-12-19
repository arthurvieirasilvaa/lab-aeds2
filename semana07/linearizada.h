typedef struct {
    int l, c; //linhas e colunas
    int *data; //dados da matriz
}Matriz;

// Aloca uma nova matriz:
void criaMatriz(Matriz *m);

// Desaloca a matriz:
void apagaMatriz(Matriz *m);

// Insere o novo valor na posição indicada:
void alteraElementoNaMatriz(Matriz *m, int lin, int col, int valor);

// Retorna o valor da matriz na posição indicada:
int consultaElementoNaMatriz(Matriz *m, int lin, int col);

// Imprime a matriz:
void imprimeMatriz(Matriz *m);

// Retorna a transposta da matriz:
Matriz* getTransporta(Matriz *m);

// Retorna a soma das matrizes:
Matriz* somaMatrizes(Matriz *m1, Matriz *m2);