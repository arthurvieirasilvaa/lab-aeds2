typedef struct {
    int l, c; //quantidade de linhas e colunas da matriz
    int *data; //dados da matriz
    int *jr; //índice das colunas dos elementos
    int *jc; //Índice do começo das linhas
    int Nz; //quantidade de elementos não nulos na matriz
} Matriz;

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