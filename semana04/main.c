#include "listaprioridade.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    ListaPrioridade lista;
    criaLista(&lista, 10);

    Pessoa p[5];
    strcpy(p[0].nome, "Beltrano");
    p[0].prioridade = 1;
    strcpy(p[1].nome, "Fulano");
    p[1].prioridade = 10;
    strcpy(p[2].nome, "Sicrano");
    p[2].prioridade = 9;
    strcpy(p[3].nome, "Beraldo");
    p[3].prioridade = 11;
    strcpy(p[4].nome, "Zutano");
    p[4].prioridade = 99;
    
    // Inserindo as 5 pessoas na lista:
    for(int i = 0; i < 5; i++) {
        if(insereNovaPessoaNoFinal(&lista, p[i]) == 0) {
            break;
        }
    }

    printf("\n");

    int prioridade;

    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
    imprimeLista(&lista);

    prioridade = chamaProximaPessoa(&lista);
   
    if(prioridade == -1) {
        printf("Ninguém foi chamado, a lista está vazia!\n");
    }

    return 0;
}