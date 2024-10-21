struct Conjunto {
    int tam;
    int *numeros;
};

// Retorna um conjunto vazio, com as sua variáveis já inicializadas:
Conjunto* cria_conjunto_vazio();

// Recebe dois conjuntos como parâmetros e retorna a união desses conjuntos:
Conjunto* uniao(Conjunto, Conjunto);

// Recebe um conjunto (passagem por referência) e o valor que será inserido no vetor:
void insere_elemento(Conjunto*, int);

// Recebe um conjunto (passagem por referência) e o valor que será removido do vetor:
void remove_elemento(Conjunto*, int);

// Recebe dois conjuntos como parâmetros e retorna a intersecção desses conjuntos:
Conjunto* interseccao(Conjunto, Conjunto);

// Recebe dois conjuntos como parâmetros e retorna a diferença desses conjuntos:
Conjunto* diferenca(Conjunto, Conjunto);

// Recebe um conjunto e um valor como parâmtros e retorna 1 (valor presenta) ou 0 (valor ausente):
int pertence_ao_conjunto(Conjunto, int);

int min(Conjunto); // recebe um conjunto como parâmetro e retorna o seu menor elemento.

int max(Conjunto); // recebe um conjunto como parâmetro e retorna o seu maior elemento.

// Recebe dois conjuntos como parâmetros e retorna 1 (conjuntos iguais) ou 0 (conjuntos diferentes):
int conjuntos_iguais(Conjunto, Conjunto);

int tamanho(Conjunto); // recebe um conjunto como parâmetro e retorna o seu tamanho.

// Recebe um conjunto como parâmetro e retorna 1 (conjunto vazio) ou 0 (conjunto não vazio):
int conjunto_vazio(Conjunto);
