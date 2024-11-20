#ifndef LISTAPRIORIDADE_H
#define LISTAPRIORIDADE_H

typedef unsigned int Prioridade;

typedef struct Pessoa_t {
    Prioridade prioridade;
    char nome[30];
} Pessoa;

typedef int Apontador;

typedef struct ListaPrioridade_t {
    Pessoa *pessoas;
    int tamanhoMaximo;
    Apontador primeiro;
    Apontador ultimo;
} ListaPrioridade;

// Funções
// A função criaLista recebe um ponteiro para uma ListaPrioridade e um inteiro que representa o tamanho máximo da lista,
// fazendo a alocação dinâmica do vetor de pessoas.
void criaLista(ListaPrioridade *lista, int tamanhoMaximo);

// A função verificarListaVazia recebe um ponteiro para uma ListaPrioridade e retorna 1 se a lista estiver vazia e 0 caso contrário.
int verificarListaVazia(ListaPrioridade *lista);

// A função insereNovaPessoaNoFinal recebe um ponteiro para uma ListaPrioridade e uma Pessoa e insere a pessoa no final da lista.
// Caso a inclusão seja bem sucedida, a função imprime "<NOMEPESSOA> adicionada com prioridade <PRIORIDADEPESSOA>\n" e retorna 1.
// Caso contrário, a função não imprime nada e retorna 0.
int insereNovaPessoaNoFinal(ListaPrioridade *lista, Pessoa pessoa);

// A função chamaProximaPessoa recebe um ponteiro para uma ListaPrioridade, imprime a mensagem "Proximo: <NOMEDAPESSOA>, <PRIORIDADE>\n"
// Depois retorna a prioridade da próxima pessoa a ser chamada.
// Se não houver pessoas na lista, a função não imprime nada e retorna -1.
int chamaProximaPessoa(ListaPrioridade *lista);

// A função imprimeLista recebe um ponteiro para uma ListaPrioridade e imprime a lista de pessoas.
// Se a lista estiver vazia, a função imprime "Lista vazia\n".
void imprimeLista(ListaPrioridade *lista);

// A função procura(), no pior caso, passa por todos os elementos da lista logo, a sua complexidade é O(n). No melhor caso, a lista está vazia - O(1):
int procura(ListaPrioridade lista, Prioridade x);

// A função quantosFaltam(), no pior caso, também passa por todos os elementos da lista logo, a sua complexidade é O(n). No melhor caso, a lista está vazia - O(1):
int quantosFaltam(ListaPrioridade lista, Prioridade x);

/*
    A função insercaoOrdenada(), no melhor caso, é O(1), ou seja, a lista está cheia ou vazia ou a pessoa será inserida no final da lista.
    No caso da pessoa ser inserida no início ou no meio da lista, no pior caso, lista.ultimo vale n-1 logo, a sua complexidade é O(n-1).
*/
int insercaoOrdenada(ListaPrioridade *lista, Pessoa pessoa);

#endif // LISTAPRIORIDADE_H