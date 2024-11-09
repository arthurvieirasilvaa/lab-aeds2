#include "listaprioridade.h"

#include <stdio.h>
#include <stdlib.h>

void criaLista(ListaPrioridade *lista, int tamanhoMaximo) {
    lista->tamanhoMaximo = tamanhoMaximo;
    lista->pessoas = (Pessoa*) malloc(lista->tamanhoMaximo * sizeof(Pessoa));
    lista->primeiro = -1;
    lista->ultimo = -1;

    if(lista->pessoas == NULL) {
        printf("ERRO AO ALOCAR MEMÓRIA!\n");
    }
}


int verificarListaVazia(ListaPrioridade *lista) {
    if(lista->primeiro == -1 && lista->ultimo == -1) {
        return 1;
    }

    return 0;
}


int insereNovaPessoaNoFinal(ListaPrioridade *lista, Pessoa pessoa) {
    // Verificando se a lista está cheia:
    if(lista->ultimo >= lista->tamanhoMaximo - 1) {
        return 0;
    }
    
    // Verificando se a lista está vazia:
    else if(verificarListaVazia(lista) == 1) {
        lista->primeiro = 0;
        lista->ultimo = 0;
        lista->pessoas[lista->ultimo] = pessoa;
    }

    // A lista não está nem cheia e nem vazia:
    else {
        lista->ultimo++;
        lista->pessoas[lista->ultimo] = pessoa;
    }

    printf("%s adicionada com prioridade %d\n", pessoa.nome, pessoa.prioridade);
    return 1;
}

int chamaProximaPessoa(ListaPrioridade *lista) {
    // Verificando se a lista está vazia:
    if(verificarListaVazia(lista) == 1) {
        return -1;
    }

    int max = 0;
    int indice;
    for(int i = lista->primeiro; i < lista->ultimo + 1; i++) {
        if(lista->pessoas[i].prioridade > max) {
            max = lista->pessoas[i].prioridade;
            indice = i;
        }
    }

    printf("Proximo: %s, %d\n", lista->pessoas[indice].nome, lista->pessoas[indice].prioridade);

    // A lista só tem essa pessoa:
    if(lista->primeiro == lista->ultimo) {
        lista->primeiro = -1;
        lista->ultimo = -1;
    }

    // A pessoa removida é a última da lista:
    else if(indice == lista->ultimo) {
        lista->ultimo--;
    }

    // A pessoa removida é a primeira da lista:
    else if(indice == lista->primeiro) {
        lista->primeiro++;
    }

    // A pessoa removida não está nem na primeira posição e nem na última:
    else {
        int aux = lista->ultimo + 1;
        // Desloca as pessoas após a pessoa que será removida para a posição anterior:
        for(int i = indice+1; i < aux; i++) {
            lista->pessoas[i-1] = lista->pessoas[i];
            lista->ultimo--;
        }   
    }

    return max;
}


void imprimeLista(ListaPrioridade *lista) {
    // Verificando se a lista está vazia:
    if(verificarListaVazia(lista) == -1) {
        printf("Lista vazia\n");
    }

    else {
        for(int i = 0; i < lista->ultimo+1; i++) {
            printf("Nome: %s, Prioridade: %d\n", lista->pessoas[i].nome, lista->pessoas[i].prioridade);
        }
    }    
    printf("\n");
}
